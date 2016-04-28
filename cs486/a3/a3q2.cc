#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

struct factor_entry {
	vector< string > variables;
	vector< bool > values;
	double result;
};

typedef vector< factor_entry > factor;

// Evaluate: Treats vector of bools as a binary digit for easy comparison
int evaluate(vector <bool> v) {
	int retval = 0;
	int base = 1;
	for(int i = v.size()-1; i >= 0; i--) {
		if(v[i])
			retval += base;
		base *= 2;
	}
	return retval;
}
// Evaluate + ignore index
int evaluate(vector <bool> v, int index) {
	int retval = 0;
	int base = 1;
	v.erase(v.begin()+index);
	for(int i = v.size()-1; i >= 0; i--) {
		if(v[i])
			retval += base;
		base *= 2;
	}
	return retval;
}

// Normalize
factor normalize(factor f) {
	double sum = 0;
	for(int i = 0; i < f.size(); i++) {
		sum += f[i].result;
	}
	for(int i = 0; i < f.size(); i++) {
		f[i].result = f[i].result / sum;
	}
	return f;
}

// Print: prints factors
void print(factor f) {
	for(int i = 0; i < f[0].variables.size(); i++) {
		cout << f[0].variables[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < f.size(); i++) {
		for(int j = 0; j < f[i].variables.size(); j++) {
			cout << f[i].values[j] << "\t";
		}
		cout << f[i].result << endl;
	}
}

factor restrict(factor f, string variable, bool value) {
	factor retval;
	for(int i = 0; i < f.size(); i++) {
		int index = find(f[i].variables.begin(), f[i].variables.end(), variable) - f[i].variables.begin();
		// If the factor doesn't contain the variable, end
		if(index >= f[i].variables.size()) {
			return f;
		}
		if(f[i].values[index] == value) {
			f[i].variables.erase(f[i].variables.begin() + index);
			f[i].values.erase(f[i].values.begin() + index);
			retval.push_back(f[i]);
		}
	}

	return retval;
}

factor multiply(factor f1, factor f2) {
	// FIND indexes of INTERSECT OF F1 & F2, VARS IN F2 not in F1
	vector<int> intersect1; vector<int> intersect2;
	vector<int> exclusive2; 
	for(int i = 0; i < f2[0].variables.size(); i++) {
		for(int j = 0; j < f1[0].variables.size(); j++) {
			if(f2[0].variables[i] == f1[0].variables[j]) {
				intersect2.push_back(i);
				intersect1.push_back(j);
				break;
			}
			else if(j == f1[0].variables.size()-1) {
				exclusive2.push_back(i);
			}
		}
	}
	// Create new factor_entrys without updating values
	while(!exclusive2.empty()) {
		int index = exclusive2.back();
		exclusive2.pop_back();
		intersect2.push_back(index);
		intersect1.push_back(f1[0].variables.size());
		int startsize = f1.size();
		for(int i = 0; i < startsize; i++) {
			f1[i].variables.push_back(f2[0].variables[index]);
			f1[i].values.push_back(1);
			f1.push_back(f1[i]);
			f1.back().values.back() = 0;
		}  
	}
	// Go through f1 and update results by matching to f2
	for(int i = 0; i < f1.size(); i++) {
		for(int j = 0; j < f2.size(); j++) {
			vector<bool> side1;
			vector<bool> side2;
			for(int k = 0; k < intersect1.size(); k++) {
				side1.push_back(f1[i].values[ intersect1[k] ]);
				side2.push_back(f2[j].values[ intersect2[k] ]);
			}
			if(evaluate(side1) == evaluate(side2)) {
				f1[i].result *= f2[j].result;
				break;
			}
		}
	}
	return f1;
}

factor sumout(factor f, string variable) {
	factor retval;
	int index = find(f[0].variables.begin(), f[0].variables.end(), variable) - f[0].variables.begin();
	if(index >= f[0].variables.size()) {
		return f;
	}
	for(int i = 0; i < f.size(); i++) {
		int eval = evaluate(f[i].values, index);
		for(int j = i+1; j < f.size(); j++) {
			if(eval == evaluate(f[j].values,index)) {
				f[j].variables.erase(f[j].variables.begin()+index);
				f[j].values.erase(f[j].values.begin()+index);
				retval.push_back(f[j]);
				retval.back().result += f[i].result;
				f.erase(f.begin()+j);
				break;
			}
		}
	}
	return retval;
}

factor inference(vector<factor> factorList, vector<string> queryVars, vector<string> hiddenVars,
				 vector<string> evidenceVars, vector<int> evidenceVals) {
	cout << "inference: restricting factors" << endl;
	for(int i = 0; i < factorList.size(); i++) {
		for(int j = 0; j < evidenceVars.size(); j++) {
			factorList[i] = restrict(factorList[i],evidenceVars[j],evidenceVals[j]);
			if(factorList[i][0].variables.size() == 0) {
				factorList.erase(factorList.begin()+1);
				i--;
			}
		}
	}
	for(int i = 0; i < factorList.size(); i++) {
		print(factorList[i]);
	}
	cout << "inference: multiplying all factors" << endl;
	while(factorList.size() > 1) {
		factor temp1 = factorList.back();
		factorList.pop_back();
		factorList.back() = multiply(temp1,factorList.back());
	}
	print(factorList[0]);
	for(int i = 0; i < hiddenVars.size(); i++) {
		cout << "inference: summing out " << hiddenVars[i] << endl;
		factorList[0] = sumout(factorList[0],hiddenVars[i]);
		print(factorList[0]);
	}
	cout << "inference: normalizing" << endl;
	return normalize(factorList[0]);
}

int main() {
	ifstream infile;
	infile.open("example3.in");
	vector<factor> fL;
	for(int i =0; i < 6; i++) {
		factor f;
		int n; infile >> n; 
		vector<string> vars;
		for(int i=0; i < n; i++){
			string s; infile >> s;
			vars.push_back(s);
		}
		for(int i=0; i < pow(2,n); i++) {
			factor_entry temp;
			temp.variables = vars;
			int o;
			for(int j = 0; j < n; j++) {
				infile >> o;
				temp.values.push_back(o);
			}
			double d;
			infile >> d;
			temp.result = d;
			f.push_back(temp);
		}
		fL.push_back(f);
	}
	infile.close();
	vector<string> qV, hV, eVars;
	vector<int> eVals;

 	// QUESTION 2
	// qV.push_back("FH");
	// hV.push_back("FB"); hV.push_back("NA"); hV.push_back("FM"); 
	// hV.push_back("NDG"); hV.push_back("FS");
	// QUESTION 3
	// qV.push_back("FS");
	// hV.push_back("NA"); hV.push_back("NDG"); hV.push_back("FB"); 
	// eVars.push_back("FH"); eVars.push_back("FM");
	// eVals.push_back(1);eVals.push_back(1);
	// QUESTION 4
	qV.push_back("FS");
	hV.push_back("NA"); hV.push_back("NDG"); 
	eVars.push_back("FH"); eVars.push_back("FM"); eVars.push_back("FB");
	eVals.push_back(1);eVals.push_back(1);eVals.push_back(1);
	// QUESTION 5
	// qV.push_back("FS");
	// hV.push_back("NDG"); 
	// eVars.push_back("FH"); eVars.push_back("FM"); eVars.push_back("FB"); eVars.push_back("NA");
	// eVals.push_back(1);eVals.push_back(1);eVals.push_back(1); eVals.push_back(1);

	factor transformed = inference(fL, qV, hV, eVars, eVals);
	print(transformed);
}

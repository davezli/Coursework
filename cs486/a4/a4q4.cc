#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

const int numAttr = 16;
static int nodeId = 0;
typedef vector< vector< double > > data;

// Decision Tree Node Struct
struct Node {
	int id;
	// Attribute Index
	int i;
	double threshold;
	vector<Node> children;
	Node(int index, double t) {
		id = nodeId; nodeId++;
		i = index;
		threshold = t;
	}
};

/****************** DTL Helper Functions *******************/
bool checkSame(data d, int index) {
	double value = d[0][index];
	for(int i = 1; i < d.size(); i++) {
		if(d[i][index] != value)
			return false;
	}
	return true;
}

Node mode(data d) {
	int tcount, fcount = 0;
	for(int i = 0; i < d.size(); i++) {
		if(d[i][numAttr] == 1) {
			tcount++;
		}
		else {
			fcount++;
		}
	}
	
	if(tcount > fcount) {
		return Node(numAttr,1);
	}
	else {
		return Node(numAttr,0);
	}
}

double I(double a, double b) {
	if(a == 0 && b == 0) return 0;
	else if(a == 0) return -b*log(b)/log(2);
	else if(b == 0) return -a*log(a)/log(2);
	return -a*log(a)/log(2)-b*log(b)/log(2);
}

double calculate_threshold(data d, int index) {
	vector<double> values;
	for(int i = 0; i < d.size(); i++) {
		values.push_back(d[i][index]);
	}
	sort(values.begin(),values.end());
	values.erase(unique(values.begin(),values.end()),values.end());
	// Count p, n
	double p,n = 0;
	for(int i = 0; i < d.size(); i++) {
		if(d[i][numAttr] == 1) p++;
		else n++;
	}
	double highestIG = 0;
	double highestvalue = values[0];
	for(int i = 1; i < values.size(); i++) {
		double th = (values[i-1]+values[i])/2;
		double IG = I(p/(p+n),n/(p+n));
		// calculate p_0, n_0, p_1, n_1
		double p0 = 0; double p1 = 0; 
		double n0 = 0; double n1 = 0;
		for(int j = 0; j < d.size(); j++) {
			if((d[j][index] >= th) == 1) {
				if(d[j][numAttr] == 1) p1++;
				else n1++;
			}
			else {
				if(d[j][numAttr] == 1) p0++;
				else n0++;				
			}
		}
		IG -= (p0+n0)/(p+n)*I(p0/(p0+n0),n0/(p0+n0));
		IG -= (p1+n1)/(p+n)*I(p1/(p1+n1),n1/(p1+n1));
		if(i == 0) {
			highestIG = IG;
			highestvalue = th;
		}
		else if(IG > highestIG) {
			highestIG = IG;
			highestvalue = th;
		}
	}

	return highestvalue;
}

int choose_attribute(data d) {
	// Count p, n
	double p,n = 0;
	for(int i = 0; i < d.size(); i++) {
		if(d[i][numAttr] == 1) p++;
		else n++;
	}
	double highestIG = 0;
	int highestindex = 0;
	for(int i = 0; i < numAttr; i++) {
		double IG = I(p/(p+n),n/(p+n));
		// calculate p_0, n_0, p_1, n_1
		double p0 = 0; double p1 = 0; 
		double n0 = 0; double n1 = 0;
		double th = calculate_threshold(d,i);
		for(int j = 0; j < d.size(); j++) {
			if((d[j][i] >= th) == 1) {
				if(d[j][numAttr] == 1) p1++;
				else n1++;
			}
			else {
				if(d[j][numAttr] == 1) p0++;
				else n0++;				
			}
		}
		IG -= (p0+n0)/(p+n)*I(p0/(p0+n0),n0/(p0+n0));
		IG -= (p1+n1)/(p+n)*I(p1/(p1+n1),n1/(p1+n1));
		if(i == 0) {
			highestIG = IG;
		}
		else if(IG > highestIG) {
			highestIG = IG;
			highestindex = i;
		}
	}
	return highestindex;
}

data partition(data d, int index, double th, int val) {
	data retval;
	for(int i = 0; i < d.size(); i++) {
		if((d[i][index] >= th) == (int)val)
			retval.push_back(d[i]);
	}
	return retval;
}

Node DTL(data d, Node def) {
	if(d.empty()) return def;
	else if(checkSame(d,numAttr)) {
		return Node(numAttr,d[0][numAttr]);
	}
	else {
		int best = choose_attribute(d);
		double th = calculate_threshold(d,best);
		Node tree = Node(best,th);
		tree.children.push_back(DTL(partition(d,best,th,0),mode(d)));
		tree.children.push_back(DTL(partition(d,best,th,1),mode(d)));
		return tree;
	}
}

int run(data d, Node tree) {
	int incorrect = 0;
	for(int j = 0; j < d.size(); j++) {
		vector<Node> stack;
		stack.push_back(tree);
		while(!stack.empty()) {
			Node copy = stack.back();
			stack.pop_back();
			// If at leaf node
			if(copy.children.empty()) {
				cout << "Horse #" << j << ": ";
				if(copy.threshold == 1)
					cout << "Healthy, which is ";
				else
					cout << "Colic, which is ";
				if(copy.threshold == d[j][numAttr])
					cout << "correct" << endl;
				else {
					cout << "incorrect" << endl;
					incorrect++;
				}
			}
			else if(d[j][copy.i] < copy.threshold) {
				stack.push_back(copy.children[0]);
			}
			else {
				stack.push_back(copy.children[1]);
			}
		}		
	}
	return incorrect;
}


/*************** IO FUNCTIONS ***************/

data readFile(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	data retval;
	string line;
	while(getline(infile,line)) {
		vector<double> datum;
		stringstream ss(line);
		double f;
		for(int i = 0; i < numAttr; i++) {
			ss >> f;

			datum.push_back(f);
			if(ss.peek() == ',') 
				ss.ignore();
		}
		string state;
		ss >> state;
		if(state == "healthy.")
			datum.push_back(1);
		else if (state == "colic.")
			datum.push_back(0);
		retval.push_back(datum);
	}
	infile.close();
	return retval;
}

void print(Node n) {
	vector<Node> stack;
	stack.push_back(n);
	while(!stack.empty()) {
		Node temp = stack.back();
		stack.pop_back();
		cout << temp.id/2 << ": ";
		if(temp.children.empty()) {
			if(temp.threshold == 1)
				cout << "healthy" << endl;
			else
				cout << "colic" << endl; 
		}
		else {
			cout << "attr " << temp.i << ", threshold " << temp.threshold;
			cout << ", children " << temp.children[0].id/2 << " and " << temp.children[1].id/2 << endl;
			stack.push_back(temp.children[1]);
			stack.push_back(temp.children[0]);
		}
	}

}

void print(data d) {
	for(int i = 0; i < d.size(); i++) {
		for(int j = 0; j < d[i].size(); j++) {
			if(j != 0) cout << ",";
			cout << d[i][j];
		}
		cout << endl;
	}
}

int main() {
	data tests = readFile("horseTest.txt");
	data training = readFile("horseTrain.txt");

	Node decisionTree = DTL(training, mode(training));
	print(decisionTree);

	cout << endl;

	int failedTests = run(tests,decisionTree);
	// int failedTraining = run(training,decisionTree);
	cout << "Failed " << failedTests << " test cases." << endl;
	// cout << "Failed " << failedTraining << " training cases." << endl;

}

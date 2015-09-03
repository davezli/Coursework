#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CheckConsistency (vector<int> A, int i, vector<int> B, int j) {
	if (i == 1 || j == B.size()-1)
		return true;
	return B[j+1] < A[i];
}

int main() {
	int k = 4;
	int Atemp[] = {1,2,3,4};
	int Btemp[] = {5.6,7,8};
	vector<int> A (Atemp, Atemp + 4);
	vector<int> B (Btemp, Btemp + 4);

	int low = 0;
	int high = min(k,static_cast<int>(A.size()));
	
	while(low<=high) {
 cout << "low: " << low << ", high: " << high << endl;
		int mid = (high+low)/2;
		int i = mid - 1;
		int j = (k-mid)-1;
		if(CheckConsistency(A,i,B,j) == false) {
			high = mid - 1;
		}
		else if (CheckConsistency(B,j,A,i) == false) {
			low = mid + 1;
		}
		else {
			low = mid;
			high = k - mid;
		}
	}

	if(low == 0)
		cout << B[k-1] << endl;
	else if(high == 0)
		cout << A[k-1] << endl;
	else
		cout << min(A[low-1],B[high-1]) << endl;
}

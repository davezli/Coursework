#include <iostream>
#include <vector>

using namespace std;

bool CheckConsistency(vector<int> A, int i, vector<int> B, int j) {
    if(i == 1 || j == (int)B.size() - 1) {
        return true;
    }
    return B[j+1] < A[i];
}

int main() {

    int

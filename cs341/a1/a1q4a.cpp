#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // Setup:
    int S;
    int n;
    cin >> S;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int OP = 0;

    // Algorithm:
    sort(A,A+n); // standard sort, takes n*log(n) time
    for(int i = 0; i < n; i++) {
        if(binary_search(A,A+n,S-A[i]))
            OP++; // n * log(n) time
    }
    cout << OP << endl;
}





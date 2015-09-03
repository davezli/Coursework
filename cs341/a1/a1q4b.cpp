#include <iostream>

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
    int i = 0;
    int j = n-1;
    while(i<j) {
        if(A[i]+A[j]==S) {
            i++;
            j--;
            OP++;
        }
        else if(A[i]+A[j]<S)
            i++;
        else if(A[i]+A[j]>S)
            j--;
    }
    OP *= 2; // to count (j,i) as well
    if(A[i] * 2 == S)
        OP++; // extra case to not doublecount (i,i)
    cout << OP << endl;
}





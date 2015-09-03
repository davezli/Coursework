#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

bool contains(int A[], int index, int num) {
    for(int i = 0; i < index; i++) {
        if(A[i] == num) return true;
    }
    return false;
}

int main() {
    int S, n, num;
    srand(time(NULL));
    S=rand()%200;
    cout << S << endl;
    n=rand()%50;
    cout << n << endl;
    int A[n];
    for(int i = 0; i < n; i++) {
        int num = rand()%100;
        while(contains(A,i,num)) {
            num = rand()%100;
        }
        A[i]=num;
    }
    sort(A,A+n);
    for(int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
}


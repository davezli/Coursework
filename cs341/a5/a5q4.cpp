#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
// Read in the two strings
    string x;
    string y;
    getline(cin,x);
    getline(cin,y);
    int m = x.size();
    int n = y.size();
// LCS2: Finding the length of the LCS
    // Initialize 2 2D vectors of size n+1 x m+1
    vector< vector<int> > c(m+1,vector<int>(n+1,0));
    vector< vector<int> > pi(m+1,vector<int>(n+1,0));
    // For pi: 0 = empty, 1 = UL, 2 = L, 3 = U
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // If same character found, increment
            // prev solution by 1 and flag with 1
            if(x[i-1] == y[j-1]) {
                c[i][j] = 1+c[i-1][j-1];
                pi[i][j] = 1;
            }
            // Otherwise, inherit from either top
            // or left and flag accordingly
            else if(c[i][j-1] > c[i-1][j]) {
                c[i][j] = c[i][j-1];
                pi[i][j] = 2;
            }
            else {
                c[i][j] = c[i-1][j];
                pi[i][j] = 3;
            }
        }
    }
    // Print out the length of the LCS here
    cout << c[m][n] << endl;
// FindLCS: Backtrack through the table made
//          when finding the length
    vector<char> seq;
    int i = m;
    int j = n;
    while(min(i,j) > 0) {
        if(pi[i][j] == 1) {
            //If it was not inherited, it's part of
            // the solution
            seq.push_back(x[i-1]);
            i--;
            j--;
            //Otherwise, move in the correct direction
        }
        else if(pi[i][j] == 2) {
            j--;
        }
        else {
            i--;
        }
        // Print & pop off stack vector
    }
    while(!seq.empty()) {
        cout << seq.back();
        seq.pop_back();
    }
    cout << endl;
}


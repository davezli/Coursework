/*
5b) This algorithm is very similar to the closest pair algorithm covered in class.
My base case is if the input has 1 or 2 barrels - I do nothing or check if they're too close respectively.
I then divide and recurse on the left side and right side.
Then, I do a Select_Candidates which takes n time, and I sort by y which takes nlogn time
Afterwards, I do a Check_Strip which takes n time.
Altogether, the algorithm takes Theta(nlogn) time.
However, because I stored the IDs of barrels too close to the barrels, sorting and printing all that takes n^2 time, so overall, my program takes n^2 time.
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct barrel {
    int ID;
    double x;
    double y;
    vector<int> tooCloseIDs;
} ;

vector<barrel> barrels;

bool sortx(const barrel &lhs, const barrel &rhs) {
    if(lhs.x == rhs.x)
        return lhs.y < rhs.y;
    return lhs.x < rhs.x;
}

bool sorty(const barrel &lhs, const barrel &rhs) {
    if(lhs.y == rhs.y)
        return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

bool sortID(const barrel &lhs, const barrel &rhs) {
    return lhs.ID < rhs.ID;
}

double bDistance(barrel A, barrel B) {
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}

void closest_pair(int lhs, int rhs, double minDistance) {
    if(lhs == rhs)
        // Base Case #1: Size 1
        return;
    if(rhs-lhs == 1) {
        // Base Case #2: Size 2
        if(bDistance(barrels[lhs],barrels[rhs])<=minDistance) {
            //TOO CLOSE!
            barrels[lhs].tooCloseIDs.push_back(barrels[rhs].ID);
            barrels[rhs].tooCloseIDs.push_back(barrels[lhs].ID);
        }
        return;
    }
    int mid = (lhs+rhs)/2;
    closest_pair(lhs,mid,minDistance);
    closest_pair(mid,rhs,minDistance);
    // SelectCandidates
    vector<barrel> candidates;
    int cand_size = 0;
    for(int i=lhs; i<rhs; i++) {
        if(fabs(barrels[i].x-barrels[mid].x) <= minDistance) {
            candidates.push_back(barrels[i]);
            cand_size++;
        }
    }
    sort(candidates.begin(),candidates.end(),sorty);
    // CheckStrip
    for(int i=0; i < cand_size; i++) {
        for(int j=i+1; j < min(cand_size,7); j++) {
            if(bDistance(candidates[i],candidates[j])<=minDistance) {
                //TOO CLOSE!
                int iID = candidates[i].ID;
                int jID = candidates[j].ID;
                for(int k=0; k < barrels.size(); k++) {
                    if(barrels[k].ID == iID)
                        barrels[k].tooCloseIDs.push_back(jID);
                    if(barrels[k].ID == jID)
                        barrels[k].tooCloseIDs.push_back(iID);
                }
            }
        }
    }
    return;
}

void prettyPrint() {
    sort(barrels.begin(),barrels.end(),sortID);
    for(int i = 0; i < barrels.size(); i++) {
        cout << barrels[i].ID;
        sort(barrels[i].tooCloseIDs.begin(),barrels[i].tooCloseIDs.end());
        for(int j = 0; j < barrels[i].tooCloseIDs.size(); j++) {
            if(//barrels[i].ID != barrels[i].tooCloseIDs[j] &&
                barrels[i].tooCloseIDs[j] != barrels[i].tooCloseIDs[j-1])
                cout << " " << barrels[i].tooCloseIDs[j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    double R;
    double D;
    cin >> n;
    cin >> R;
    cin >> D;
    for(int i = 0; i < n; i++) {
        barrel buffer;
        cin >> buffer.ID;
        cin >> buffer.x;
        cin >> buffer.y;
        barrels.push_back(buffer);
    }
    sort(barrels.begin(),barrels.end(),sortx);
    closest_pair(0,n-1,2*R+D);
    prettyPrint();
}

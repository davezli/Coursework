/*
5b)
My adjacency list implementation for this program takes O(V+E) time, where
V is the number of vertices and E is the number of edges. This is because it
searches through each vertex once and each edge once - it never repeats because
it checks if it has already searched using the color array.

An adjacency matrix implementation would take O(V^2) time, where V is the number
of vertices. This is because for each vertex v, it has to traverse through its
row of size V to find its neighbors, for a total of V*V time.

*/
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;


int main() {
    vector< vector<int> > musicians;
    int num;
    string line;

//  Getting first num
    getline(cin,line);
    istringstream iss(line);
    iss >> num;

//  Initializing color and dist arrays
    int color[num+1]; // -1 = white, 0 = gray, 1 = black
    int dist[num+1]; // index num+1 b/c we're apparently math students

//  Filling out rest of array
    while(getline(cin,line)) {
        istringstream iss(line);
        musicians.push_back(vector<int>(istream_iterator<int>(iss),
                                        istream_iterator<int>() ) );
    }

//  Start BFS Here
    fill_n(color, num+1, -1);
    fill_n(dist, num+1, -1);
    color[1] = 0;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < musicians[u-1].size(); i++) {
            int v = musicians[u-1][i];
            if(color[v] == -1) {
                color[v] = 0;
                q.push(v);
                dist[v] = dist[u]+1;
            }
            color[u] = 1;
        }
    }

//	Print
    for(int i = 1; i <= num; i++) {
        if(dist[i] != -1)
            cout << dist[i];
        cout << endl;
    }
}


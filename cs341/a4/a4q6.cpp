#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

int tick = 0; // time is a protected word
bool DAG = true;
vector<int> stack;
vector< vector<int> > graph;
int num;

void DFSvisit(int v, int *color, int *parent, int *finish, vector<int> order) {
    while(DAG) {
        order.push_back(v);
        color[v] = 0;
        tick++;
        if(!graph[v-1].empty()) {
            for(int adj = 0; adj < graph[v-1].size(); adj++) {
                int w = graph[v-1][adj];
                if(color[w] == -1) {
                    parent[w] = v;
                    DFSvisit(w, color, parent, finish, order);
                }
                if(color[w] == 0) {
                    DAG = false;
                    int i = 0;
                    while(order[i] != w) {
                        i++;
                    }
                    while(i < order.size()) {
                        cout << order[i] << " ";
                        i++;
                    }
                    cout << w << endl;
                    break;
                }
            }
        }
        color[v] = 1;
        stack.push_back(v);
        tick++;
        finish[v] = tick;
    }
}

int main() {
    string line;

//  Getting first num
    getline(cin,line);
    istringstream iss(line);
    iss >> num;

//  Filling out rest of array
    while(getline(cin,line)) {
        istringstream iss(line);
        graph.push_back(vector<int>(istream_iterator<int>(iss),
                                    istream_iterator<int>() ) );
    }

//	Initialize
    int color[num+1]; // white = -1, grey = 0, black = 1
    int parent[num+1]; // -1 = null
    int finish[num+1];
    for(int i = 0; i < num+1; i++) {
        color[i] = -1;
        parent[i] = -1;
        finish[i] = -1;
    }

    vector<int> order;
//	Iterate
    for(int v = 1; v < num+1; v++) {
        if(color[v] == -1) {
            DFSvisit(v, color, parent, finish, order);
        }
    }

    if(DAG) {
        for(int i = stack.size() - 1; i >= 0; i--) {
            cout << stack[i];
            if(i != 0)
                cout << " ";
        }
        cout << endl;
    }
}


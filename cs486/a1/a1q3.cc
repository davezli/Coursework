#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

struct City {
	string name;
	int x,y;
	City() {};
	City(string n, int a, int b) {
		name = n; x = a; y = b;
	}
};

struct Node {
	// Current City
	City city;
	// List of Cities to visit
	vector<City> cities;
	string remainingCities;
	// For A*
	double f,g,h;
	// Path taken so far
	string path;
	Node(City c, vector<City> v) {
		city = c; cities = v; 
		f,g,h = 0.0;
		remainingCities,path = "";
		for(int i = 0; i < cities.size(); i++) {
			remainingCities += cities[i].name;
		}
	}
};

double eucliddistance(City a, City b) {
	// Returns euclidian distance between two cities
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double evaluate_heuristic(Node n) {
	// Finds the longest distance between the current node and nodes not yet reached
	// and the distance from that node to end 
	double longest = 0;
	double total = 0;
	if(n.cities.size() > 0) {
		longest = eucliddistance(n.city,n.cities[0]);
		total = longest;
	}
	for(int i = 1; i < n.cities.size();i++) {
		if(longest < eucliddistance(n.city,n.cities[i])) {
			longest = eucliddistance(n.city,n.cities[i]);
			total = longest+eucliddistance(n.cities[i],n.cities[0]);
		}
	}
	return total;
}

void search(Node node) {
	// A* search algorithm
	// Initiate open with start
	vector<Node> open;
	open.push_back(node);
	double nodesExpanded = 0;

	while(!open.empty()) {
		// Find node with smallest f and push off
		double smallestf = open[0].f;
		int smallesti = 0;
		for(int i = 1; i < open.size();i++) {
			if(open[i].f < smallestf) {
				smallestf = open[i].f;
				smallesti = i;
			}
		}
		Node q = open[smallesti];
		open.erase(open.begin()+smallesti);
		// If the node to expand is a goalstate, we're done
		if(q.remainingCities=="") {
				cout <<  q.path << endl;
				cout << "Expanded " << nodesExpanded << ", cost: " << q.g << endl;
				return;
		}
		// Expand node by generating successors
		vector<Node> children;
		for(int i = 0; i < q.cities.size(); i++) {
			nodesExpanded++;
			// Expand starting node last for roundtrip
			if(q.cities[i].name == node.city.name && 
				q.cities.size() != 1) {
				continue;
			}
			vector<City> citycopy = q.cities;
			citycopy.erase(citycopy.begin()+i);
			Node child = Node(q.cities[i],citycopy);
			child.path = q.path + q.cities[i].name;		
			children.push_back(child);
		}

		//Evaluate successors
		for(int i = 0; i < children.size(); i++) {
			bool skip = false;
			children[i].g = q.g + eucliddistance(children[i].city,q.city);
			children[i].h = evaluate_heuristic(children[i]);
			children[i].f = children[i].g + children[i].h;
			//Don't add to open queue if it's already in it with smaller cost
			//Must be at the same city & have same unvisited cities to evaluate
			for(int j = 0; j < open.size(); j++) {
				if(open[j].remainingCities == children[i].remainingCities &&
					open[j].city.name == children[i].city.name) {
					if(open[j].g < children[i].g) {
						skip = true;
						break;
					}
					else {
						open.erase(open.begin()+j);
					}
				}
			}
			if(!skip) {
				open.push_back(children[i]);
			}
		}
	}
	return;
}

int main() {
	vector<City> cities;
	int n,x,y; string name, line;
	getline(cin,line);
	stringstream ss(line);
	ss >> n;
	for(int i = 0; i < n; i++) {
		getline(cin,line);
		stringstream ss(line);
		ss >> name >> x >> y;
		City buffer = City(name,x,y);
		cities.push_back(buffer);
	}
	Node start = Node(cities[0],cities);
	start.path = cities[0].name;
	search(start);
}
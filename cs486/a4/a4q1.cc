#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector< vector<double> > grid;

// Discount Factor
const double discount = 0.9;

// Saving the initial grid & actions
grid initial;
vector< vector< string > > action_grid;
vector< vector< string > > initial_actions;

void print(grid g) {
	cout.precision(3);
	cout.setf(ios::fixed,ios::floatfield);
	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 3; x++) {
			cout << "\t" << g[y][x]; 
		}
		cout << "\t";
		for(int x = 0; x < 3; x++) {
			cout << "\t" << action_grid[y][x]; 
		}
		cout << endl;
	}
	cout << endl;
}

// Functions that evaluate value of moves
double move_up(grid g, int x, int y) {
	double total = 0;
	if(y-1 < 0)
		total += 0.8 * g[y][x];
	else 
		total += 0.8 * g[y-1][x];
	// left
	if(x-1 < 0)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y][x-1];
	// right
	if(x+1 > 2)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y][x+1];

	total *= discount;
	total += initial[y][x];
	return total;
}

double move_down(grid g, int x, int y) {
	double total = 0;
	if(y+1 > 2)
		total += 0.8 * g[y][x];
	else
		total += 0.8 * g[y+1][x];
	// left
	if(x-1 < 0)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y][x-1];
	// right
	if(x+1 > 2)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y][x+1];
	total *= discount;
	total += initial[y][x];
	return total;
}

double move_left(grid g, int x, int y) {
	double total = 0;
	if(x-1 < 0)
		total += 0.8 * g[y][x];
	else
		total += 0.8 * g[y][x-1];
	// up
	if(y-1 < 0)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y-1][x];
	// down
	if(y+1 > 2)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y+1][x];
	total *= discount;
	total += initial[y][x];
	return total;
}

double move_right(grid g, int x, int y) {
	double total = 0;
	if(x+1 > 2)
		total += 0.8 * g[y][x];
	else
		total += 0.8 * g[y][x+1];
	// up
	if(y-1 < 0)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y-1][x];
	// down
	if(y+1 > 2)
		total += 0.1 * g[y][x];
	else 
		total += 0.1 * g[y+1][x];
	total *= discount;
	total += initial[y][x];
	return total;
}

// Finding optimal moves and updating values
grid iterate(grid g) {
	grid retval = g;
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			// Found ending stage
			if(y == 0 && x == 2) {
				continue;
			}
			double highest = move_up(g,x,y);
			action_grid[y][x] = "↑";
			if(move_down(g,x,y) > highest) {
				highest = move_down(g,x,y);
				action_grid[y][x] = "↓";
			}
			if(move_left(g,x,y) > highest) {
				highest = move_left(g,x,y);
				action_grid[y][x] = "←";
			}
			if(move_right(g,x,y) > highest) {
				highest = move_right(g,x,y);
				action_grid[y][x] = "→";
			}
			retval[y][x] = highest;
		}
	}
	return retval;
}

int main() {

	// Setup action_grid
	vector<string> sr; sr.push_back("?"); sr.push_back("?"); sr.push_back("?");
	action_grid.push_back(sr); action_grid.push_back(sr); action_grid.push_back(sr);
	action_grid[0][2] = "";
	initial_actions = action_grid;
	// Setup grid & store initial values
	grid g;
	vector<double> row1; row1.push_back(100); row1.push_back(-1); row1.push_back(10);
	vector<double> row2; row2.push_back(-1); row2.push_back(-1); row2.push_back(-1);
	vector<double> row3; row3.push_back(-1); row3.push_back(-1); row3.push_back(-1);
	g.push_back(row1);	g.push_back(row2);	g.push_back(row3);
	initial = g;
	cout << "r = 100" << endl;
	for(int i = 1; i < 25; i++) {
		g = iterate(g);
	}
	print(g);
	cout << "r = -3" << endl;
	initial[0][0] = -3;
	g = initial;
	action_grid = initial_actions;
	for(int i = 1; i < 25; i++) {
		g = iterate(g);
	}
	print(g);
	cout << "r = 0" << endl;
	initial[0][0] = 0;
	g = initial;
	action_grid = initial_actions;
	for(int i = 1; i < 25; i++) {
		g = iterate(g);
	}
	print(g);
	cout << "r = 3" << endl;
	initial[0][0] = 3;
	g = initial;
	action_grid = initial_actions;
	for(int i = 1; i < 25; i++) {
		g = iterate(g);
	}
	print(g);
}

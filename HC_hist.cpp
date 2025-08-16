#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void hillClimb(char start, map<char, vector<char>>& graph, map<char, int>& heuristic) {
    char current=start;         // To store the path taken
    vector<char> visited;          // Extended list (visited nodes)
    visited.push_back(current);

    cout << "Path: " << current << " ";
    while (current!='G') {
        if (graph[current].empty()) {
            cout << "\nNo better neighbour found" << endl;
            return;
        }
        char best =graph[current][0];
        for (char neighbor : graph[current]) {
            if (heuristic[neighbor] < heuristic[best]) {
                best=neighbor;
            }
        }
        if (heuristic[best]>=heuristic[current]) {
            cout << "\nNo better neighbour found" << endl;
            return;
        }
        current = best;
        visited.push_back(current);
        cout << current << " ";
    }
    cout << "Extended list: ";
    for (char node : visited) cout << node << " ";
    cout << endl;
}
int main() {
    
    map<char, vector<char>> graph;
    graph['S'] = {'A', 'B'};
    graph['A'] = {'B', 'D'};
    graph['B'] = {'A', 'C'};
    graph['C'] = {'E'};
    graph['D'] = {'G'};
    graph['E'] = {};
    graph['G'] = {};

    map<char, int> heuristic = {
        {'S', 5},
        {'A', 3},
        {'B', 4},
        {'C', 2},
        {'D', 1},
        {'E', 6},
        {'G', 0}
    };
    hillClimb('S', graph, heuristic);
    return 0;
}
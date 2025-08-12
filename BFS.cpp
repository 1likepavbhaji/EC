#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
bool found = false;
void bfs(char start, map<char, vector<char>>& graph) {
    set<char> visited;
    queue<char> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        
        cout << node << " ";
        if(node=='G'){
            found = true;
            break;
        }

        for (char neighbor : graph[node]) { 
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
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

    cout << "BFS starting from S: ";
    bfs('S', graph);

    return 0;
}


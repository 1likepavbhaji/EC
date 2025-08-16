#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

bool found = false;

void bfs(char start, map<char, vector<char>>& graph) {
    set<char> visited;
    queue<char> q;
    map<char, char> parent; // store how we reached each node

    visited.insert(start);
    q.push(start);
    parent[start] = '\0'; // start has no parent

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        cout << node << " ";

        if (node == 'G') {
            found = true;
            cout << "\nPath to goal: ";
            
            // reconstruct path using parent map
            stack<char> path;
            for (char cur = 'G'; cur != '\0'; cur = parent[cur])
                path.push(cur);

            while (!path.empty()) {
                cout << path.top() << " ";
                path.pop();
            }
            cout << endl;
            break;
        }

        for (char neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                parent[neighbor] = node; // remember parent
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

    if (!found) cout << "Goal not found\n";

    return 0;
}

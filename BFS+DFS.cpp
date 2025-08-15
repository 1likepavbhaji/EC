#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

map<char, vector<char>> graph;
set<char> visited;
vector<char> path;
bool found = false;

void dfs(char node) {
    if (found) return; // stop if goal already found
    visited.insert(node);
    path.push_back(node);

    if (node == 'G') {
        found = true;
        return;
    }

    for (char neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor);
            if (found) return;
        }
    }
}

void bfs_dfs(char start) {
    queue<char> q;
    visited.insert(start);
    path.push_back(start);
    q.push(start);

    while (!q.empty() && !found) {
        char node = q.front();
        q.pop();

        for (char neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor); // dive deep from here
                if (found) return;
                q.push(neighbor); // if DFS didn't find goal, add to BFS queue
            }
        }
    }
}

int main() {
    // Graph definition
    graph['S'] = {'A', 'B'};
    graph['A'] = {'B', 'D'};
    graph['B'] = {'C'};
    graph['C'] = {'E'};
    graph['D'] = {'G'};
    graph['E'] = {};
    graph['G'] = {};

    bfs_dfs('S');

    // Print path
    if (found) {
        cout << "Path to G: ";
        for (char c : path) cout << c << " ";
    } else {
        cout << "Goal not found";
    }
}

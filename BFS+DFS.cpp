#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

map<char, vector<char>> graph;
set<char> visited;
vector<char> path;
bool found=false;

void dfs(char node) {
    if (found) return; 
    visited.insert(node);
    path.push_back(node);

    if (node=='G') {
        found=true;
        return;
    }

    for (char neighbor: graph[node]) {
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
        char node=q.front();
        q.pop();
        for (char neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor); 
                if (found) return;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    graph['S'] = {'A', 'B'};
    graph['A'] = {'B', 'D'};
    graph['B'] = {'C'};
    graph['C'] = {'E'};
    graph['D'] = {'G'};
    graph['E'] = {};
    graph['G'] = {};

    bfs_dfs('S');

    if (found) {
        cout << "Path to G: ";
        for (char c :path) cout << c << " ";
    } else {
        cout << "Goal not found";
    }
}

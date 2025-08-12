#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

int main() {
    // Graph adjacency list
    map<char, vector<char>> graph;
    graph['S'] = {'A', 'B'};
    graph['A'] = {'B', 'D'};
    graph['B'] = {'A', 'C'};
    graph['C'] = {'E'};
    graph['E'] = {};
    graph['D'] = {'G'};
    graph['G'] = {};

    char start = 'S';
    char goal = 'G';

    // Stack stores (node, path_so_far)
    stack<pair<char, vector<char>>> st;
    set<char> visited;

    st.push({start, {start}});

    while (!st.empty()) {
        auto [node, path] = st.top();
        st.pop();

        if (node == goal) {
            cout << "Path found: ";
            for (char n : path) cout << n << " ";
            cout << endl;
            return 0; // Stop after finding first path
        }

        if (visited.find(node) == visited.end()) {
            visited.insert(node);

            // Push neighbors in reverse order to maintain DFS order
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    vector<char> new_path = path;
                    new_path.push_back(*it);
                    st.push({*it, new_path});
                }
            }
        }
    }

    cout << "No path found from " << start << " to " << goal << endl;
    return 0;
}

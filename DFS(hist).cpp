#include <iostream>
#include <vector>
using namespace std;

const int MAX=100;
int goal=6;
bool found=false;

int graph[MAX][MAX];
bool visited[MAX];
int n;

char labels[MAX] = {'S', 'A', 'B', 'C', 'D', 'E', 'G'};
vector<int> history; 

void dfs(int node) {
    visited[node] = true;
    history.push_back(node); 

    if (node==goal) {
        found=true;
        cout << "Path to goal: ";
        for (int i : history)
            cout << labels[i] << " ";
        cout << endl;
        return;
    }

    for (int i =0; i<n; i++) {
        if (graph[node][i] ==1 && !visited[i]) {
            dfs(i);
            if (found) return; 
        }
    }

    history.pop_back(); 
}
int main() {
    n = 7;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            graph[i][j]=0;

graph[0][2] = 1; 
graph[2][0] = 1; 

graph[0][1] = 1;
graph[1][0] = 1;

graph[1][2] = 1; 
graph[2][1] = 1; 

graph[2][3] = 1; 
graph[3][2] = 1; 

graph[3][5] = 1; 
graph[5][3] = 1; 

graph[1][4] = 1; 
graph[4][1] = 1; 

graph[4][6] = 1; 
graph[6][4] = 1;

    for (int i =0; i<n; i++)
        visited[i] =false;

    dfs(0);

    if (!found) cout << "Goal not found\n";
}

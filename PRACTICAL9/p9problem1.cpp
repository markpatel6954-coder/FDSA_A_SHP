#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100];
bool visited[100];
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v])
        if (!visited[u]) DFS(u);
}
void BFS(int start) {
    fill(visited, visited + 100, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v])
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
    }
}
int main() {
    int n, m, u, v, start;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> start;
    DFS(start);
    cout << endl;
    BFS(start);
    return 0;
}
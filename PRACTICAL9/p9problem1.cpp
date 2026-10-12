#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[100];
bool visited[100];
void DFS(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : g[u])
        if (!visited[v]) DFS(v);
}
void BFS(int s) {
    queue<int> q;
    fill(visited, visited + 100, false);
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : g[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
}
int main() {
    int n, m, u, v, s;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s;
    DFS(s);
    cout << "\n";
    BFS(s);
}
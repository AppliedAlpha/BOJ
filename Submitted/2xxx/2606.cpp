#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v, t1, t2, c = 0;
bool visited[101];
vector<int> adj[1001];

void initVisited() {
    for (bool & i : visited) i = false;
}

void bfs(int i) {
    queue<int> q;
    visited[i] = true;
    //cout << i << " ";
    q.push(i);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            //cout << u << " ";
            q.push(u);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    for (int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());
    initVisited();
    bfs(1);
    for (bool & i : visited) if (i) c++;
    cout << c-1;
}
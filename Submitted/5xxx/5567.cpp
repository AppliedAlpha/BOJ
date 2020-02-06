#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

int bfs() {
    queue<int> queue;
    visited[1] = true;
    int c = 0;
    for (auto i : adj[1]) {
        if (visited[i]) continue;
        visited[i] = true;
        c++;
        queue.push(i);
    }
    while (!queue.empty()) {
        int index = queue.front();
        queue.pop();
        for (auto i : adj[index]) {
            if (visited[i]) continue;
            visited[i] = true;
            c++;
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto & i : adj) sort(i.begin(), i.end());
    cout << bfs();
    return 0;
}
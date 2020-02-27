#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> visited(100002);
vector<vector<int>> adjacent;

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i : adjacent[now]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = now;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    adjacent.resize(n+1);
    int tmp = n - 1;
    while (tmp--) {
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    for (auto i : adjacent) sort(i.begin(), i.end());
    bfs();
    for (int i=2; i<=n; i++) cout << visited[i] << '\n';
    return 0;
}

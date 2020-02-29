#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define num first
#define cnt second
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;
vector<vector<int>> adjacent;
int n, m, x, y;

int bfs() {
    queue<pii> q;
    q.push(make_pair(1, 0));
    visited[1] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.num == n) return now.cnt;
        for (auto i : adjacent[now.num]) {
            if (!visited[i]) {
                q.push(make_pair(i, now.cnt + 1));
                visited[i] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    visited.resize(n+1);
    adjacent.resize(n+1);
    while (m--) {
        cin >> x >> y;
        adjacent[x].push_back(y);
    }
    for (auto i : adjacent) sort(i.begin(), i.end());
    cout << bfs();
    return 0;
}

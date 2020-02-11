#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
unordered_map<ll, int> visited;

int bfs(ll a, ll b) {
    if (a == b) return 1;
    queue<ll> q;
    q.push(a);
    visited[a] = 1;
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        ll next[2] = {now * 2, (now * 10) + 1};
        for (auto i : next) {
            if (visited[i] || i > 1e9 || i > b) continue;
            q.push(i);
            visited[i] = visited[now] + 1;
            if (i == b) return visited[i];
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    cout << bfs(a, b);
    return 0;
}
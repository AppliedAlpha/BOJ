#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> adj(10001); //node, cost
int cnt, goal, dp[10001];

int di(int cur) {
    int & res = dp[cur];
    if (res != -1) return res;
    if (cur == goal) return res = 0;
    res = di(cur + 1) + 1;
    for (auto & i : adj[cur]) res = min(res, di(i.first) + i.second);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v, w;
    cin >> cnt >> goal;
    while (cnt--) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    fill(dp, dp+10001, -1);
    cout << di(0);
    return 0;
}
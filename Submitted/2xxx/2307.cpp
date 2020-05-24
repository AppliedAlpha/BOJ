#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

vector<vector<pii>> adj; //node, cost
vector<int> parent;
int n, m, u, v, w, _max = -i32_max;

int di(int x, int y) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; //-dist, target_node
    vector<int> dist(n+1, i32_max);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int now = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        if (dist[now] < dis) continue;

        for (auto i : adj[now]) {
            int next = i.first, cost = i.second + dis;
            if ((now == x && next == y) || (now == y && next == x)) continue;
            if (dist[next] > cost) {
                pq.push({cost, next});
                dist[next] = cost;
                parent[next] = now;
            }
        }
    }
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n+1);
    parent.assign(n+1, -1);
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int _min = di(0, 0);
    int ver = n;
    while (parent[ver] != -1) {
        int a = ver;
        int b = parent[ver];
        _max = max(_max, di(a, b));
        ver = b;
    }

    cout << (_max == i32_max ? -1 : _max - _min);
    return 0;
}
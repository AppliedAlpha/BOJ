#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1000000007
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> vg; //node, cost
vector<int> dist;
vector<bool> checked;
priority_queue<pii> pq; //-dist, target_node

//How To Understand
void di(int n, int start) {
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        if (checked[now]) continue;
        for (auto i : vg[now]) {
            int next = i.first, cost = i.second;
            if (dist[now] + cost < dist[next]) {
                dist[next] = dist[now] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    vg.resize(n+1);
    dist.resize(n+1);
    checked.resize(n+1);
    while (m--) {
        cin >> u >> v >> w;
        vg[u].emplace_back(v, w);
    }
    fill(dist.begin(), dist.end(), INF);
    di(n, k);
    for (int i=1; i<=n; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}
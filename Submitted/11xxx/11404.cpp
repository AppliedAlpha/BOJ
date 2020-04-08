#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000LL;
ll dist[101][101];
int adj[101][101], n, m, a, b, c;

// Floyd-Warshall Algorithm
ll _min(ll x, ll y) { return x > y ? y : x; }

void init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = _min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        adj[a][b] = (adj[a][b] ? _min(adj[a][b], c) : c);
    }
    init();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << (dist[i][j] >= INF ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }
    return 0;
}
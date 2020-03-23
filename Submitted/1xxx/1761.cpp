#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pii {
    int adj, di;
};

bool visited[40003];
int n, m, a, b, c, dep[40003], dist[40003], parent[40003][17];
vector<vector<pii>> adjacent;

// BASED ON 11438
void dfs(int idx, int depth, int distance) {
    visited[idx] = true;
    dep[idx] = depth;
    dist[idx] = distance;
    for (pii u : adjacent[idx]) {
        if (visited[u.adj]) continue;
        parent[u.adj][0] = idx; // u의 부모 (parent[u][0]) 지정 -> idx
        dfs(u.adj, depth + 1, distance + u.di);
    }
}

void par() {
    // 연속해서 부모 찾기 (j: index, i: degree)
    for (int i=1; i<17; i++)
        for (int j=1; j<=n; j++)
            parent[j][i] = parent[parent[j][i-1]][i-1];
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y); // dep[x] <= dep[y]
    for (int i=16; i>=0; i--) {
        // 깊이 차이가 있으면 조상 찾아가기
        if (dep[y] - dep[x] >= (1 << i))
            y = parent[y][i];
    }
    if (x == y) return x; // 같은 조상을 만났으면 return
    // 조상이 다르다면 -> 같을 때까지 조상 찾기
    for (int i=16; i>=0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    adjacent.resize(n+1);
    for (int i=0; i<n-1; i++) { // 이어진 노드 처리
        cin >> a >> b >> c;
        adjacent[a].push_back({b, c});
        adjacent[b].push_back({a, c});
    }
    dfs(1, 0, 0); // DFS
    par(); // 부모 및 조상 전처리
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
    }
    return 0;
}
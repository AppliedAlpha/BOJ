#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, a, b;
vector<vector<int>> parent;
vector<ll> res;

void dfs(int x) {
    for (int i : parent[x]) {
        res[i] += res[x];
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    parent.resize(n+1);
    res.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a;
        if (i > 1) parent[a].push_back(i);
    }
    while (m--) {
        cin >> a >> b;
        res[a] += b;
    }
    dfs(1);
    for (int i=1; i<=n; i++) cout << res[i] << ' ';
    return 0;
}

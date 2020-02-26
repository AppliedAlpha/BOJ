#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<bool> visited;

int bfs(int f, int s, int g, int u, int d) {
    queue<pii> q;
    q.push({s, 0});
    visited[s] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == g) return now.second;
        vector<int> tmp = {now.first + u, now.first - d};
        for (auto i : tmp) {
            if (i <= f && i > 0) {
                if (!visited[i]) {
                    //cout << i << ' ';
                    q.push({i, now.second + 1});
                    visited[i] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    if ((s < g && u == 0) || (s > g && d == 0)) {
        cout << "use the stairs";
        return 0;
    }
    else {
        visited.resize(f+1);
        int res = bfs(f, s, g, u, d);
        if (res < 0) cout << "use the stairs";
        else cout << res;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<int> visited(100002), route_back(100002), res;

int bfs(int st, int en) {
    queue<pii> q;
    q.push({st, 0});
    visited[st] = true;
    route_back[st] = st;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == en) return now.second;
        vector<int> tmp = {now.first * 2, now.first + 1, now.first - 1};
        for (auto i : tmp) {
            if (i >= 0 && i <= 100000) {
                if (!visited[i]) {
                    q.push({i, now.second + 1});
                    visited[i] = true;
                    route_back[i] = now.first;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int st, en, tmp;
    cin >> st >> en;
    cout << bfs(st, en) << '\n';
    tmp = en;
    while (tmp != route_back[tmp]) {
        res.push_back(tmp);
        tmp = route_back[tmp];
    }
    res.push_back(st);
    for (int i=res.size()-1; i>=0; i--) cout << res[i] << ' ';
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<int> visited(100002);

int bfs(int st, int en) {
    queue<pii> q;
    q.push({st, 0});
    visited[st] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == en) return now.second;
        vector<pii> tmp = {
                {now.first * 2, 0},
                {now.first - 1, 1},
                {now.first + 1, 1}};
        for (auto i : tmp) {
            if (i.first >= 0 && i.first <= 100000) {
                if (!visited[i.first]) {
                    q.push({i.first, now.second + i.second});
                    visited[i.first] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int st, en;
    cin >> st >> en;
    cout << bfs(st, en);
    return 0;
}

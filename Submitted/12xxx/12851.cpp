#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<int> visited(100002, 0), min_time(100002, 0);

int bfs(int st, int en) {
    queue<pii> q;
    q.push({st, 0});
    min_time[st] = 0;
    visited[st] = 1;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (now.first == en) return now.second;
        vector<int> tmp = {now.first * 2, now.first + 1, now.first - 1};
        for (auto i : tmp) {
            if (i >= 0 && i <= 100000) {
                if (!visited[i]) {
                    q.push({i, now.second + 1});
                    visited[i] = visited[now.first];
                    min_time[i] = now.second + 1;
                }
                else if (min_time[i] >= min_time[now.first] + 1) {
                    visited[i] += visited[now.first];
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
    bfs(st, en);
    cout << min_time[en] << '\n' << visited[en];
    return 0;
}
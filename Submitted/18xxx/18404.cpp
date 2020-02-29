#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef struct {
    int x, y, cnt;
} mov;
int n, m, _x, _y;
vector<pii> tmp = {
        {2, 1}, {2, -1},
        {-2, 1}, {-2, -1},
        {1, 2}, {1, -2},
        {-1, 2}, {-1, -2},
};
map<pii, int> cnt;

int bfs() {
    queue<mov> q;
    mov first = {_x, _y, 0};
    q.push(first);
    cnt[{first.x, first.y}] = 0;
    while (!q.empty()) {
        mov now = q.front();
        q.pop();
        for (auto i : tmp) {
            int next_x = now.x + i.first;
            int next_y = now.y + i.second;
            if (next_x >= 1 && next_x <= n) {
                if (next_y >= 1 && next_y <= n) {
                    if (!cnt[{next_x, next_y}]) {
                        q.push({next_x, next_y, now.cnt + 1});
                        cnt[{next_x, next_y}] = now.cnt + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> _x >> _y;
    bfs();
    while (m--) {
        int _a, _b;
        cin >> _a >> _b;
        cout << cnt[{_a, _b}] << ' ';
    }
    return 0;
}

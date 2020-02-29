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
int t, n, _x, _y;
vector<pii> tmp = {
        {2, 1}, {2, -1},
        {-2, 1}, {-2, -1},
        {1, 2}, {1, -2},
        {-1, 2}, {-1, -2},
};
map<pii, int> cnt;

// ~= 18404
int bfs(int a, int b) {
    queue<mov> q;
    mov first = {_x, _y, 0};
    q.push(first);
    cnt[{first.x, first.y}] = 0;
    while (!q.empty()) {
        mov now = q.front();
        q.pop();
        if (a == now.x && b == now.y) return now.cnt;
        for (auto i : tmp) {
            int next_x = now.x + i.first;
            int next_y = now.y + i.second;
            if (next_x >= 0 && next_x < n) {
                if (next_y >= 0 && next_y < n) {
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
    cin >> t;
    while (t--) {
        cnt.clear();
        int _a, _b;
        cin >> n >> _x >> _y >> _a >> _b;
        cout << bfs(_a, _b) << '\n';
    }
    return 0;
}

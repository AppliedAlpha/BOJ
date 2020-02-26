#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef struct {
    int x, y, cnt;
} mov;
vector<vector<int>> visited(8, vector<int>(8));

//0~7;
int bfs(char stt, int st, char enn, int en) {
    queue<mov> q;
    mov first = {stt-'a', st-1, 0};
    mov last = {enn-'a', en-1, -1};
    q.push(first);
    visited[first.x][first.y] = true;
    while (!q.empty()) {
        mov now = q.front();
        q.pop();
        if (now.x == last.x && now.y == last.y) return now.cnt;
        vector<pii> tmp = {
                {2, 1}, {2, -1},
                {-2, 1}, {-2, -1},
                {1, 2}, {1, -2},
                {-1, 2}, {-1, -2},
        };
        for (auto i : tmp) {
            int next_x = now.x + i.first;
            int next_y = now.y + i.second;
            if (next_x >= 0 && next_x < 8) {
                if (next_y >= 0 && next_y < 8)
                    if (!visited[next_x][next_y]) {
                        q.push({next_x, next_y, now.cnt + 1});
                        visited[next_x][next_y] = true;
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
    char stt, enn;
    cin >> stt >> st >> enn >> en;
    cout << bfs(stt, st, enn, en);
    return 0;
}

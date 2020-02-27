#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
char arr[101][101];
bool visited[101][101];
int n, m;

vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pii bfs() {
    queue<pii> q;
    int w = 0, b = 0, temp_cnt;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            temp_cnt = 0;
            if (!visited[i][j]) {
                visited[i][j] = true;
                temp_cnt++;
                q.push({i, j});
                cout << "[" << i << ", " << j << ". " << temp_cnt << "]\n";
                while (!q.empty()) {
                    pii now = q.front();
                    q.pop();
                    for (auto a : dir) {
                        int next_x = now.x + a.x, next_y = now.y + a.y;
                        if (next_x >= 0 && next_x < n) {
                            if (next_y >= 0 && next_y < m) {
                                if (!visited[next_x][next_y] && arr[next_x][next_y] == arr[i][j]) {
                                    visited[next_x][next_y] = true;
                                    temp_cnt++;
                                    q.push({next_x, next_y});
                                    cout << "[" << next_x << ", " << next_y << ".. " << temp_cnt << "]\n";
                                }
                            }
                        }
                    }
                }
                if (arr[i][j] == 'W') w += temp_cnt * temp_cnt;
                else if (arr[i][j] == 'B') b += temp_cnt * temp_cnt;
            }
        }
    }
    return make_pair(w, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    pii res = bfs();
    cout << res.x << ' ' << res.y;
    return 0;
}

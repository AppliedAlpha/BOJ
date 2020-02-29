#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
int arr[1002][1002], n, m;

void bfs(int _x, int _y) {
    queue<pii> q;
    q.push({_x, _y});
    arr[_x][_y] = 2;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        vector<pii> tmp = {
                {now.x - 1, now.y}, {now.x + 1, now.y},
                {now.x, now.y + 1}, {now.x, now.y - 1}
        };
        for (auto i : tmp) {
            if (i.x >= 0 && i.x < n && i.y >= 0 && i.y < m) {
                if (arr[i.x][i.y] == 1) {
                    q.push({i.x, i.y});
                    arr[i.x][i.y] = arr[now.x][now.y] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _x = 0, _y = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                _x = i;
                _y = j;
            }
        }
    }
    bfs(_x, _y);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << (arr[i][j] ? arr[i][j] - 2 : 0) << ' ';
        }
        cout << '\n';
    }
    return 0;
}

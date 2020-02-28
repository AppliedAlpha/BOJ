#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt = 0, _max = 0;
int a[501][501];
bool check[501][501];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// ~= 1303
int dfs(int x, int y) {
    int ret = 1;
    check[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!check[nx][ny] && a[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> a[i][j];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!check[i][j] && a[i][j]) {
                cnt++;
                _max = max(dfs(i, j), _max);
            }
        }
    }
    cout << cnt << '\n' << _max;
    return 0;
}

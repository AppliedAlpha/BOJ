#include <iostream>
#include <algorithm>
using namespace std;
int n, best = 10000, cnt = 2, map[101][101];
bool coast[101][101];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

//TRY
void dfs(int x, int y) {
    map[x][y] = cnt;
    int r, c;
    for (int k=0; k<4; k++) {
        r = x + dx[k];
        c = y + dy[k];
        if (r >= 0 && r < n && c >= 0 && c < n) {
            if (map[r][c] == 1) dfs(r, c);
            else if (map[r][c] == 0) coast[x][y] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _x = 0, _y = 0;
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> map[i][j];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] == 1) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (coast[i][j]) {
                for (int ii=i; ii<=min(n-1, i+best); ii++) {
                    for (int jj=max(0, j-best); jj<=min(n-1, j+best); jj++) {
                        if (map[i][j] != map[ii][jj] && coast[ii][jj]) {
                            best = min(best, abs(i-ii) + abs(j-jj)-1);
                        }
                    }
                }
            }
        }
    }
    cout << best;
    return 0;
}

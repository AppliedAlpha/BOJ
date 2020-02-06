#include <iostream>
using namespace std;
char map[101][101];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

//RETRY
int solve(int n) {
    if (n < 3) return 0;
    bool flag;
    int res = (n-2)*(n-2);
    for (int i=1; i<n-1; i++) {
        for (int j = 1; j < n - 1; j++) {
            flag = false;
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (map[nx][ny] == '#') continue;
                if (map[nx][ny] == '0') flag = true;
            }
            if (flag) res--;
            else {
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (map[nx][ny] == '#' || map[nx][ny] == '0') continue;
                    map[nx][ny]--;
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> map[i][j];
    cout << solve(n);
    return 0;
}
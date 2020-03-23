#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 2147483600, CENTER = 0;
int dp[5][5], tmp[5][5]; // Left: i, Right: j

int move(int from, int to) {
    if (from == to) return 1;
    if (from == CENTER) return 2;
    if ((from + to) % 2) return 3;
    return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int action, res = INF;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) dp[i][j] = INF;
    dp[0][0] = 0;

    while (true) {
        cin >> action;
        if (!action) break;
        for (int i=0; i<5; i++) for (int j=0; j<5; j++) tmp[i][j] = INF;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (dp[i][j] == INF) continue;
                if (action != j) tmp[action][j] = min(dp[i][j] + move(i, action), tmp[action][j]);
                if (action != i) tmp[i][action] = min(dp[i][j] + move(j, action), tmp[i][action]);
            }
        }
        for (int i=0; i<5; i++) for (int j=0; j<5; j++) dp[i][j] = tmp[i][j];
    }
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) res = min(res, dp[i][j]);
    cout << res;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000009
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;
int board[501][501];

// 1x4, 2x2, (3x2 of 4)
int shape[19][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int res = 0, n, m;

void cal(int x, int y) {
    for (int i=0; i<19; i++) {
        int tmp = 0;
        for (int j=0; j<4; j++) {
            int dx = x + shape[i][j][0];
            int dy = y + shape[i][j][1];
            if (dx < 0 || dx >= n) break;
            else if (dy < 0 || dy >= m) break;
            else tmp += board[dx][dy];
        }
        res = max(res, tmp);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> board[i][j];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cal(i, j);
    }
    cout << res;
    return 0;
}
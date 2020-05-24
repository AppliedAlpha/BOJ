#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define y first
#define x second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>(n+1));

    // 2n+1
    if (n % 2) {
        pii cur = {1, n/2 + 1};

        for (int i=1; i<=n*n; i++) {
            v[cur.y][cur.x] = i;
            pii next = cur;
            next.y--;
            next.x++;
            if (next.y < 1) next.y = n;
            if (next.x > n) next.x = 1;
            if (v[next.y][next.x] != 0) {
                next = {cur.y+1, cur.x};
            }
            cur = next;
        }
    }

        // 4n
    else if (!(n % 4)) {
        vector<vector<int>> w(n+1, vector<int>(n+1));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] = (i-1) * n + j;
                w[i][j] = n*n - v[i][j] + 1;
            }
        }

        vector<pii> diff = {{0, 1}, {0, 2},
                            {1, 0}, {1, 3},
                            {2, 0}, {2, 3},
                            {3, 1}, {3, 2}};

        for (int i=1; i<=n/4; i++) {
            for (int j=1; j<=n/4; j++) {
                pii base = {(i-1) * 4 + 1, (j-1) * 4 + 1};
                for (const auto & k : diff) {
                    v[base.y + k.y][base.x + k.x] = w[base.y + k.y][base.x + k.x];
                }
            }
        }
    }

        // 4n+2
    else {

        // Base 2n+1
        pii cur = {1, (n/2)/2 + 1};
        vector<vector<int>> w(n/2 + 1, vector<int>(n/2 + 1));
        int base = n*n/4;

        for (int i=1; i<=base; i++) {
            w[cur.y][cur.x] = i;
            pii next = cur;
            next.y--;
            next.x++;
            if (next.y < 1) next.y = n/2;
            if (next.x > n/2) next.x = 1;
            if (w[next.y][next.x] != 0) {
                next = {cur.y+1, cur.x};
            }
            cur = next;
        }

        // Filling Base Multipliers
        for (int i=1; i<=n/2; i++) {
            for (int j=1; j<=n/2; j++) {
                v[i][j] = (j <= (n-2)/4 ? 3 : 0);
            }
        }
        swap(v[(n/2)/2 + 1][1], v[(n/2)/2 + 1][(n/2)/2 + 1]);

        for (int i=1; i<=n/2; i++) {
            for (int j=1; j<=n/2; j++) {
                v[i+(n/2)][j] = (v[i][j] ? 0 : 3);

                v[i][j+(n/2)] = (j <= (n+6)/4 ? 2 : 1);
                v[i+(n/2)][j+(n/2)] = (v[i][j+(n/2)] == 2 ? 1 : 2);
            }
        }

        // Filling
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] *= base;
                v[i][j] += w[(i-1) % (n/2) + 1][(j-1) % (n/2) + 1];
            }
        }
    }

    // Printing
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
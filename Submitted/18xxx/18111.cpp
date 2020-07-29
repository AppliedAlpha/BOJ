#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define mod 1'000'000'007
#define i32_max 2'147'483'646
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n, m, b;
int v[501][501] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> b;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    int time = i32_max, height = -1;
    for (int i=0; i<=256; i++) {
        int need = 0, now = 0;
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                int diff = v[j][k] - i;
                need -= diff;
                now += diff * (diff >= 0 ? 2 : -1);
            }
        }
        if (need <= b) {
            if (now <= time) {
                time = now;
                height = i;
            }
        }
    }
    cout << time << ' ' << height;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int arr[20][20], n, res = 2147483646;
bool check[20];

void solve(int cnt, int idx) {
    if (idx == n) return;
    if (cnt == n/2) {
        int a = 0, b = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (check[i] && check[j]) a += arr[i][j];
                if (!check[i] && !check[j]) b += arr[i][j];
            }
        }
        res = min(res, abs(a-b));
        return;
    }
    check[idx] = true;
    solve(cnt + 1, idx + 1);
    check[idx] = false;
    solve(cnt, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0, 0);
    cout << res;
    return 0;
}
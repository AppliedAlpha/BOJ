#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() { //parametric search
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, low = 0, high = 0, res = -1;
    cin >> n >> k;
    v.resize(n);
    for (auto & i : v) {
        cin >> i;
        high += i;
    }
    while (low <= high) {
        int m = (low + high) / 2;
        int ms = 0, diff = 12345679, cnt = 1;
        bool flag = false;
        for (auto i : v) {
            ms += i;
            if (ms >= m) {
                diff = min(diff, ms);
                ms = 0;
                cnt++;
            }
            if (cnt > k) {
                res = max(res, diff);
                flag = true;
                break;
            }
        }
        if (flag) {
            low = m + 1;
            res = max(res, diff);
        }
        else high = m - 1;
    }
    cout << res;
    return 0;
}
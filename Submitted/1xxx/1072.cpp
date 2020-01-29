#include <iostream>
using namespace std;
typedef long long ll;
ll L = 2000000000;

int ratio(ll a, ll b) {
    return (b * 100) / a;
}

int solve(int x, int y) {
    if (ratio(x, y) == ratio(x+L, y+L)) return -1;
    ll left = 0, right = L; //left 이기면 승률 미변동, right 이기면 변동
    while (left + 1 < right) {
        ll mid = (left + right) / 2;
        if (ratio(x, y) == ratio(x+mid, y+mid)) left = mid;
        else right = mid;
    }
    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    cout << solve(x, y);
    return 0;
}
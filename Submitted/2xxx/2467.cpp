#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;

// == 2470, ~= 2470
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp, res1, res2;
    pii _min = {0, 1};
    cin >> n;
    v.resize(n);
    for (auto & i : v) {
        cin >> tmp;
        if (tmp > 0) i = {tmp, 1};
        else i = {-tmp, -1};
    }
    sort(v.begin(), v.end());
    v[0].first *= v[0].second;
    for (int i=0; i<n-1; i++) {
        v[i+1].first *= v[i+1].second;
        if (abs(v[i].first + v[i+1].first) <= abs(v[_min.first].first + v[_min.second].first))
            _min = {i, i+1};
    }
    res1 = v[_min.first].first;
    res2 = v[_min.second].first;
    if (res1 > res2) swap(res1, res2);
    cout << res1 << ' ' << res2;
    return 0;
}
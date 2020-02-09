#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cnt, res = 0;
    cin >> n;
    v.resize(n);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        cnt = 1;
        for (int j=1; (j < 5 && i+j<v.size()); j++) {
            if (v[i+j] < v[i] + 5) cnt++;
        }
        res = max(res, cnt);
    }
    cout << 5 - res;
    return 0;
}
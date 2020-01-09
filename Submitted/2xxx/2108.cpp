#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<int> v;

bool compare(const pii &a, const pii &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double sum = 0;
    cin >> n;
    v.resize(n);
    for (auto & i : v) {
        cin >> i;
        sum += i;
    }
    sort(v.begin(), v.end());
    cout << (int)floor((sum/n) + 0.5) << '\n';
    cout << v[n/2] << '\n';
    vector<pii> vv;
    for (auto i : v) {
        if (vv.empty()) {
            vv.emplace_back(i, 1);
            continue;
        }
        if (vv.back().first == i) {
            auto tmp = vv.back();
            tmp.second++;
            vv.pop_back();
            vv.push_back(tmp);
        }
        else {
            vv.emplace_back(i, 1);
        }
    }
    sort(vv.begin(), vv.end(), compare);
    if (vv.size() > 1)
        cout << ((vv[0].second == vv[1].second) ? vv[1].first : vv[0].first) << '\n';
    else cout << vv[0].first << '\n';
    cout << v.back() - v.front();
}
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp, res = 0;
    vector<pii> v;
    vector<int> index;
    for (int i=0; i<8; i++) {
        cin >> tmp;
        v.emplace_back(tmp, i+1);
    }
    sort(v.rbegin(), v.rend());
    for (int i=0; i<5; i++) {
        res += v[i].first;
        index.push_back(v[i].second);
    }
    sort(index.begin(), index.end());
    cout << res << '\n';
    for (auto i : index) cout << i << ' ';
    return 0;
}
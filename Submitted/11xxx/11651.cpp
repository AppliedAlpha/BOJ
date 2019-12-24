#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        v.emplace_back(y, x);
    }
    sort(v.begin(), v.end());
    for (const auto &a : v) cout << a.second << ' ' << a.first << '\n';
}
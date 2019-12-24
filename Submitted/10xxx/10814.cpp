/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, string> pis;
vector<pis> v;

bool comp(const pis &a, const pis &b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    string y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    stable_sort(v.begin(), v.end(), comp);
    for (const auto &a : v) cout << a.first << ' ' << a.second << '\n';
}
 */

#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> v(201);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    string y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i=1; i<201; i++) {
        if (!(v[i].empty())) {
            for (const auto &a : v[i]) {
                cout << i << ' ' << a << '\n';
            }
        }
    }
}
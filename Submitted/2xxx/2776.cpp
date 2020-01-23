#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, target;
    cin >> n;
    while (n--) {
        cin >> m;
        v.clear();
        v.resize(m);
        for (auto & i : v) cin >> i;
        sort(v.begin(), v.end());
        cin >> k;
        while (k--) {
            cin >> target;
            cout << binary_search(v.begin(), v.end(), target) << '\n';
        }
    }
}
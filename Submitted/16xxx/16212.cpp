#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end());
    for (auto i : v) cout << i << ' ';
    return 0;
}
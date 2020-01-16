#include <iostream>
#include <algorithm>
#include <vector>
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
    cout << ((n%2) ? v[n/2] : v[n/2-1]);
    return 0;
}
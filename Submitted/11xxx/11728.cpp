#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    v.resize(n+m);
    for (int & i : v) cin >> i;
    sort(v.begin(), v.end());
    for (auto a : v) cout << a << ' ';
}
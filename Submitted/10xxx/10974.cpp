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
    for (int i=1; i<=n; i++) v.emplace_back(i);
    do {
        for (auto i : v) cout << i << ' ';
        cout << '\n';
    }
    while (next_permutation(v.begin(), v.end()));
}
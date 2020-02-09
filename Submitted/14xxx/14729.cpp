#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end());
    cout << setprecision(3) << fixed;
    for (int i=0; i<7; i++) cout << v[i] << '\n';
    return 0;
}
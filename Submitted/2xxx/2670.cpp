#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <utility>
#include <numeric>
#include <algorithm>
#define mod 1'000'000'007
using namespace std;

vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n);
    double part = 1, res = numeric_limits<double>::min();

    for (auto & i : v) cin >> i;
    for (int i=0; i<n; i++) {
        part = max(1.0, part) * v[i];
        res = max(part, res);
    }
    cout << fixed << setprecision(3) << res;
    return 0;
}
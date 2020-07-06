#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>
#define i32_max 2147483646
using namespace std;
typedef long long i64;
typedef double f64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto & i : v) cin >> i;

    f64 min_w = i32_max;
    for (int i=0; i<=n-k; i++) {
        for (int j=i+k-1; j<n; j++) {
            f64 m = 0, b = 0, w;
            for (int h=i; h<=j; h++) m += v[h];
            m /= (f64)(j - i + 1);
            for (int h=i; h<=j; h++) {
                b += (v[h] - m) * (v[h] - m);
            }
            b /= (f64)(j - i + 1);
            w = sqrt(b);
            min_w = min(w, min_w);
        }
    }

    cout.precision(50);
    cout << fixed << min_w;
    return 0;
}
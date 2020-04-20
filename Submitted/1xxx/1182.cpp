#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;
int n, s, temp, res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    v.resize(n);
    for (auto & i : v) cin >> i;
    int p = (int)(pow(2, n));
    for (int i=1; i<p; i++) { // Bit-Masking
        temp = 0;
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) temp += v[j];
        }
        if (temp == s) res++;
    }
    cout << res;
}
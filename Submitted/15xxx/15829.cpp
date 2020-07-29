#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define mod 1'234'567'891
#define i32_max 2'147'483'646
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int l;
string str;
i64 sum = 0LL;
i64 _pow[51] = {1, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> l >> str;
    for (int i=1; i<=50; i++) {
        _pow[i] = _pow[i-1] * 31;
        _pow[i] %= mod;
    }
    for (size_t i=0; i<str.length(); i++) {
        sum += (str[i]-'a'+1) * _pow[i];
        sum %= mod;
    }
    cout << sum;

    return 0;
}
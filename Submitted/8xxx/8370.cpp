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
#define mod 1'000'000'007
#define i32_max 2'147'483'646
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> d;
    cout << a*b + c*d;
    return 0;
}
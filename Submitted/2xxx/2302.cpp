#include <iostream>
#include <iomanip>
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
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

i64 arr[41] = {1, 1, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i=2; i<41; i++) arr[i] = arr[i-2] + arr[i-1];

    int n, m;
    i64 a = 0, b, res = 1;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> b;
        res *= arr[b-a-1];
        a = b;
    }
    cout << res * arr[n-a];
    return 0;
}
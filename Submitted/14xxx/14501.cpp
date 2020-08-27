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

vector<int> v(26);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[i+1] = max(v[i], v[i+1]);
        v[i+a] = max(v[i+a], v[i]+b);
    }
    cout << v[n];
    return 0;
}
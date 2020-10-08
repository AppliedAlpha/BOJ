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

int arr[100001] = {0, 1, 1, 2, 2, 1, 2, 1, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i=8; i<=n; i++) {
        arr[i] = min(min(arr[i-7], arr[i-5]), min(arr[i-2], arr[i-1])) + 1;
    }
    cout << arr[n];
    return 0;
}
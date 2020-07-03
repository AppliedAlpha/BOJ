#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    n = 1000 - n;
    int res = 0, i = 0;
    int a[6] = {500, 100, 50, 10, 5, 1};
    while (n > 0) {
        if (n >= a[i]) {
            n -= a[i];
            res++;
        }
        else i++;
    }
    cout << res;
    return 0;
}
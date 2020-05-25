#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int n, m;
    scanf("%d:%d", &n, &m);
    int x = gcd(n, m);
    printf("%d:%d", n/x, m/x);
    return 0;
}
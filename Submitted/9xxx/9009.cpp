#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cassert>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n, m;
int fibo[45] = {0, 1, };

void solve() {
    cin >> m;
    int i = 44;
    stack<int> s;
    while (m > 0) {
        assert(i >= 0);
        if (m >= fibo[i]) {
            m -= fibo[i];
            s.push(fibo[i]);
        }
        else i--;
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i=2; i<45; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    cin >> n;
    while (n--) solve();
    return 0;
}
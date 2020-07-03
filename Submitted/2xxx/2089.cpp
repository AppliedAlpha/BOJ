#include <iostream>
#include <vector>
#include <stack>
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
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    do {
        int left = n % (-2);
        n /= (-2);
        if (left < 0) {
            left = 1;
            n++;
        }
        s.push(left);
    } while (n != 0);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}
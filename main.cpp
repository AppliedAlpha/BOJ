#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000009
#define endl cout << '\n'
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int solve(string str, bool dir) {
    bool push = false;
    int l = 0, r = str.length() - 1;
    while (l <= r) {
        if (str[l] != str[r]) {
            if (!push) {
                if (dir) r--;
                else l++;
                push = true;
                continue;
            }
            else {
                if (dir) return solve(str, 0);
                else return 2;
            }
        }
        l++;
        r--;
    }
    return push;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << solve(str, 1);
        endl;
    }
    return 0;
}
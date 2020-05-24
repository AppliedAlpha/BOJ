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

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Distances: ";
    for (int i=0; i<s1.length(); i++) {
        cout << s2[i] - s1[i] + (s1[i] <= s2[i] ? 0 : 26) << " ";
    }
    endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) solve();
    return 0;
}
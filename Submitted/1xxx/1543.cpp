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
string str, sub;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getline(cin, str);
    getline(cin, sub);
    int res = 0;
    if (str.length() < sub.length()) cout << res;
    else {
        for (int i=0; i<=str.length()-sub.length(); i++) {
            if (str.substr(i, sub.length()) == sub) {
                res++;
                i += sub.length()-1;
            }
        }
        cout << res;
    }
    return 0;
}
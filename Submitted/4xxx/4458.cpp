#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
using namespace std;
typedef long long i64;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    string temp;
    getline(cin, temp);
    while (n--) {
        string str;
        getline(cin, str);
        str[0] -= str[0] >= 'a' ? 32 : 0;
        cout << str << '\n';
    }
    return 0;
}
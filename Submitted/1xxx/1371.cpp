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

/*
 greater<int> DESC;
 less<int> ASC (Default);
 compare a < b (ASC), a > b (DESC)
 */

int n, m;
string str;
vector<int> v(26);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (!(cin >> str).eof()) {
        for (auto i : str) {
            if (i >= 'a' && i <= 'z') {
                v[i-'a']++;
            }
        }
        str.clear();
    }
    int cnt = 0;
    for (int i=0; i<26; i++) cnt = cnt > v[i] ? cnt : v[i];
    for (int i=0; i<26; i++) if (v[i] == cnt) cout << (char)('a'+i);
    return 0;
}
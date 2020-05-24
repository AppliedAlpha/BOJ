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
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s1 >> s2;
    cout << (s1.length() >= s2.length() ? "go" : "no");
    return 0;
}
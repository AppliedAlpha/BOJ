#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> v(26, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    string s;
    cin >> s;
    for (char i : s) v[i-'a']++;
    for (auto a : v) cout << a << ' ';
}
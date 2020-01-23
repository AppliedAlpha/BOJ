#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    string s;
    vector<string> v;
    map<string, int> m;
    cin >> a >> b;
    c = a + b;
    while (c--) {
        cin >> s;
        m[s]++;
        if (m[s] == 2) v.emplace_back(s);
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (const auto& i : v) cout << i << '\n';
    return 0;
}
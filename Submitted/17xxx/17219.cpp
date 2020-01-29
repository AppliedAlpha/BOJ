#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string a, b, c;
    map<string, string> mp;
    cin >> n >> m;
    while (n--) {
        cin >> a >> b;
        mp[a] = b;
    }
    while (m--) {
        cin >> c;
        cout << mp[c] << '\n';
    }
    return 0;
}

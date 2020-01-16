#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<string, int> psi;

bool comp(const psi &a, const psi &b) {
    return a.second >= b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp;
    string s;
    cin >> n;
    while (n--) {
        map<string, int> map;
        cin >> m;
        while (m--) {
            cin >> s >> tmp;
            map[s] += tmp;
        }
        vector<psi> v(map.begin(), map.end());
        sort(v.begin(), v.end(), comp);
        cout << v[0].first << '\n';
    }
    return 0;
}
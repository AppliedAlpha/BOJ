#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, int> psi;

bool comp(const psi& a, const psi& b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    map<string, int> m;
    cin >> n;
    while (n--) {
        cin >> s;
        m[s]++;
    }
    vector<psi> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    cout << v[0].first;
    return 0;
}
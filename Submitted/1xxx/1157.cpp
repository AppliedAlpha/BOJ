#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define x first
#define y second
using namespace std;
typedef long long i64;
typedef double f64;
typedef pair<int, int> pii;
typedef pair<char, int> pci;

bool cmp(const pci &a, const pci &b) {
    return a.y > b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    map<char, int> m;
    vector<pci> v;
    cin >> str;

    for (auto i : str) {
        if (i >= 'a' && i <= 'z') i -= 32;
        m[i]++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        v.push_back({it->x, it->y});
    }

    sort(all(v), cmp);
    if (v.size() == 1) cout << v[0].x;
    else if (v[0].y == v[1].y) cout << '?';
    else cout << v[0].x;

    return 0;
}
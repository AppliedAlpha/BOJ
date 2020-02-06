#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;


void solve() {
    int n;
    string str;
    cin >> n >> str;
    str = ' ' + str;
    vector<pii> v(str.length());
    map<pii, vector<int>> m;
    v[0] = {0, 0};
    if (n == 1) {
        cout << "-1";
        return;
    };
    for (int i=1; i<str.length(); i++) {
        if (str[i] == 'L') v[i] = {v[i-1].x - 1, v[i-1].y};
        if (str[i] == 'R') v[i] = {v[i-1].x + 1, v[i-1].y};
        if (str[i] == 'U') v[i] = {v[i-1].x, v[i-1].y + 1};
        if (str[i] == 'D') v[i] = {v[i-1].x, v[i-1].y - 1};
    }
    bool exist = false;
    vector<pii> existable;
    int min = 200000, minx = 0, miny = 0;
    for (int i=0; i<v.size(); i++) {
        m[{v[i].x, v[i].y}].push_back(i);
    }
    for (int i=0; i<v.size(); i++) {
        int tar = m[{v[i].x, v[i].y}].size();
        if (tar >= 2) {
            exist = true;
            existable.emplace_back(v[i].x, v[i].y);
        }
    }
    sort(existable.begin(), existable.end());
    existable.erase(unique(existable.begin(), existable.end()), existable.end());
    for (auto i : existable) {
        for (int j=0; j<m[{i.x, i.y}].size()-1; j++) {
            int gap = m[{i.x, i.y}][j+1] - m[{i.x, i.y}][j];
            if (min > gap) {
                min = gap;
                minx = m[{i.x, i.y}][j];
                miny = m[{i.x, i.y}][j+1];
                if (min == 2) break;
            }
        }
    }
    if (!exist) {
        cout << "-1";
        return;
    }
    cout << minx+1 << ' ' << miny;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
        cout << '\n';
    }
    return 0;
}
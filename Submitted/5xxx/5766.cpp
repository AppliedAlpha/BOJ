#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) // 같은 회수 호출 시
        return a.first < b.first;
    return a.second > b.second; // 많은게 우선
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp;
    while (cin >> n >> m) {
        if (!n && !m) break;
        map<int, int> rank; //num, call
        map<int, int>::iterator it;
        for (int i=0; i<n*m; i++) {
            cin >> tmp;
            it = rank.find(tmp);
            if (it != rank.end()) rank[tmp]++;
            else rank[tmp] = 1;
        }
        vector<pair<int, int>> v(rank.begin(), rank.end());
        sort(v.begin(), v.end(), cmp);
        bool win = false;
        for (int i=1; i<v.size(); i++) {
            if (win) {
                if (v[i-1].second != v[i].second) break;
                cout << v[i].first << ' ';
            }
            else {
                if (v[i-1].second != v[i].second) {
                    win = true;
                    cout << v[i].first << ' ';
                }
            }
        }
        cout << '\n';
    }
}
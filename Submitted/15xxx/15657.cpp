#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; //4 2 9871: 17 18 19 ... 98 99
    vector<int> index(n);
    for (int i=0; i<n; i++) cin >> index[i];
    sort(index.begin(), index.end()); //index 0~n-1: 사용하는 숫자 리스트
    vector<pair<int, int>> v(m, {index[0], 0});
    //v[0~m-1]: 사용된 숫자, 사용된 숫자 인덱스
    while (v[0].second != n) {
        bool check = false;
        int tmp = v[0].first;
        for (int i=0; i<m; i++) {
            if (tmp > v[i].first) break;
            tmp = v[i].first;
            if (i == m-1) check = true;
        }
        if (check) {
            for (auto a : v) cout << a.first << ' ';
            cout << '\n';
        }
        v[m-1].second++;
        for (int i=m-1; i>0; i--) {
            if (v[i].second >= n) {
                v[i].second -= n;
                v[i-1].second++;
            }
            v[i].first = index[v[i].second];
        }
        if (v[0].second != n) v[0].first = index[v[0].second];
    }
}
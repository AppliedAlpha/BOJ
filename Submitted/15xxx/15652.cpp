#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; //4 2: 11 12 13 ... 43 44
    vector<int> v(m, 1);
    while (v[0] != n+1) {
        bool check = false;
        int tmp = v[0];
        for (int i=0; i<m; i++) {
            if (tmp > v[i]) break;
            tmp = v[i];
            if (i == m-1) check = true;
        }
        if (check) {
            for (auto a : v) cout << a << ' ';
            cout << '\n';
        }
        v[m-1]++;
        for (int i=m-1; i>0; i--) {
            if (v[i] >= n+1) {
                v[i] -= n;
                v[i-1]++;
            }
        }
    }
}

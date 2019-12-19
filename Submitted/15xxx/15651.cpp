#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; //4 2: 11 12 13 ... 43 44
    vector<int> v(m, 1);
    while (v[0] != n+1) {
        for (auto a : v) cout << a << ' ';
        v[m-1]++;
        for (int i=m-1; i>0; i--) {
            if (v[i] >= n+1) {
                v[i] -= n;
                v[i-1]++;
            }
        }
        cout << '\n';
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    vector<int> index(n, 0);
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> tmp;
        v[i] = tmp;
    }
    sort(v.begin(), v.end());
    for (int i=0; i<m; i++) index[i] = 1;
    do {
        for (int i=0; i<n; i++) {
            if (index[i]) cout << v[i] << ' ';
        }
        cout << '\n';
    } while (prev_permutation(index.begin(), index.end()));
}

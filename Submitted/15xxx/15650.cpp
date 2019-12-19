#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> index(n, 0);
    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = i+1;
    for (int i=0; i<m; i++) index[i] = 1;
    do {
        for (int i=0; i<n; i++) {
            if (index[i]) cout << i+1 << ' ';
        }
        cout << '\n';
    } while (prev_permutation(index.begin(), index.end()));
}

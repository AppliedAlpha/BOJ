#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<int> index(n, 0);
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < 6; i++) index[i] = 1;
        do {
            for (int i = 0; i < n; i++) {
                if (index[i]) cout << v[i] << ' ';
            }
            cout << '\n';
        } while (prev_permutation(index.begin(), index.end()));
        cout << '\n';
    }
}

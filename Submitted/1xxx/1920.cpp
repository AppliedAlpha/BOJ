#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp;
    cin >> n;
    vector<int> a(1, 0);
    for (int i=0; i<n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin()+1, a.end());
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> tmp;
        cout << (int)binary_search(a.begin()+1, a.end(), tmp) << '\n';
    }
}
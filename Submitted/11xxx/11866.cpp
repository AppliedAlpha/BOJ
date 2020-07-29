#include <iostream>
#include <vector>
using namespace std;

// ~= 1158
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, pos = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = i+1;
    cout << '<';
    while (true) {
        pos = (pos + k - 1) % v.size();
        if (v.size() > 1) cout << v[pos] << ", ";
        else {
            cout << v[pos] << '>';
            break;
        }
        v.erase(v.begin() + pos);
    }
}
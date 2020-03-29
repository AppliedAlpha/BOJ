#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, pos, i;
vector<int> v;

// ~= 3745
// LIS in O(n log n)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> i;
        pos = lower_bound(v.begin(), v.end(), i) - v.begin();
        if (pos == v.size()) v.push_back(i);
        else if (v[pos] > i) v[pos] = i;
    }
    cout << v.size() << '\n';
    return 0;
}
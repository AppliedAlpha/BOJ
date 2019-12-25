#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp, k;
    cin >> n >> k;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << '\n';
}
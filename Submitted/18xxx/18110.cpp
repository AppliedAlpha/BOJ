#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n) {
        int sum = 0;
        v.resize(n); //0~n-1
        for (auto & i : v) {
            cin >> i;
            sum += i;
        }
        int c = (int)round(n * 0.15);
        sort(v.begin(), v.end());
        for (int i=0; i<c; i++) sum -= (v[i] + v[n-1-i]);
        cout << round((double)sum/(n-2*c));
    }
    else cout << 0;
    return 0;
}
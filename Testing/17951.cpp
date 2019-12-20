#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//누적합? 부분합?
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tmp, partial_sum = 0;
    cin >> n >> m;
    vector<int> v, v_sum;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        v.push_back(tmp);
        partial_sum += tmp;
        v_sum.push_back(partial_sum);
    }
    for (int i=0; i<n; i++) {
        cout << v[i] << ' ' << v_sum[i] << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> value;
vector<int> sum;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    value.resize(n + 1);
    sum.resize(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> value[i];
    }
    value[0] = 0;
    sum[0] = 0;
    sum[1] = value[1];
    sum[2] = value[1] + value[2];
    for (int i=3; i<=n; i++) {
        sum[i] = max(value[i-1] + sum[i-3], sum[i-2]) + value[i];
    }
    cout << sum[n];
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000007
using namespace std;
vector<int> v, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n+1);
    res.resize(n+1);
    v[0] = res[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        res[i] = MAX;
        if (i != 1) {
            for (int j=1; j<=i; j++) {
                res[i] = min(res[i], res[i-j] + v[j]);
            }
        }
        else res[1] = v[1];
    }
    cout << res[n];
    return 0;
}
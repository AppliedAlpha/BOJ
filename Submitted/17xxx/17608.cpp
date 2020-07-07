#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, _max = 0, res = 0;
    cin >> n;
    vector<int> v(n);
    for (auto & i : v) cin >> i;

    for (int i=n-1; i>=0; i--) {
        if (v[i] > _max) {
            _max = v[i];
            res++;
        }
    }

    cout << res;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int cal(const vector<int> &v, int k) {
    int sum = 0;
    for (auto i : v) {
        if (i >= k) sum += k;
        else sum += i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, _max = 0, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
        if (v[i] > _max) _max = v[i];
    }
    cin >> a;
    if (sum <= a) {
        cout << _max;
    }
    else {
        int x = 0, y = _max-1;
        while (x <= y) {
            int k = (x+y)/2;
            if (cal(v, k) <= a && cal(v, k+1) > a) {
                cout << k;
                break;
            }
            if (cal(v, k) < a) x = k+1;
            else y = k-1;
        }
    }
}
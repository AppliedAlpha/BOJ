#include <iostream>
using namespace std;
int n, k, _max, _min;

int main() {
    cin >> n >> k;
    _max = _min = k;
    for (int i=1; i<n; i++) {
        cin >> k;
        if (k > _max) _max = k;
        else if (k < _min) _min = k;
    }
    cout << _min << " " << _max;
}
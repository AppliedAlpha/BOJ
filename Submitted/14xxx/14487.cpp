#include <iostream>
using namespace std;

int main() {
    int n, t, max = 0, sum = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        sum += t;
        if (t > max) max = t;
    }
    cout << sum-max;
}
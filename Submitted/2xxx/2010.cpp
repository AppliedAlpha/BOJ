#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, tmp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum-n+1;
}
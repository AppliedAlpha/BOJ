#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, sum = 0, n = 1;
    cin >> a >> b;
    while (n*(n+1)/2 < a) n++;
    for (int i=a; i<=b; i++) {
        if (n*(n+1)/2 < i) n++;
        sum += n;
    }
    cout << sum;
}
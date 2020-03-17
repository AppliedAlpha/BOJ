#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b = 0;
    for (int i=0; i<5; i++) {
        cin >> a;
        b += a*a;
    }
    cout << b % 10;
    return 0;
}
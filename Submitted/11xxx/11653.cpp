#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i=2;
    cin >> n;
    while (n > 1) {
        while (!(n%i)) {
            n /= i;
            cout << i << '\n';
        }
        i++;
    }
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    cin >> n;
    while (n--) {
        int sum = 0;
        cin >> tmp;
        int i = 5;
        while (true) {
            sum += tmp/i;
            i *= 5;
            if (i > tmp) break;
        }
        cout << sum << '\n';
    }
}
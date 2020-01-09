#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    long long sum = 1L;
    int i = 1;
    if (x == y) cout << 0;
    else {
        while (true) {
            sum += i / 2;
            if (y - x >= sum && y - x < sum + (i + 1) / 2) break;
            i++;
        }
        cout << i;
    }
    return 0;
}
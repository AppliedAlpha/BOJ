#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        long long sum = 1L;
        int i = 1;
        while (true) {
            sum += i/2;
            if (y-x >= sum && y-x < sum+(i+1)/2) break;
            i++;
        }
        cout << i << '\n';
    }
    return 0;
}
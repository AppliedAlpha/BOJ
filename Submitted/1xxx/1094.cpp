#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cnt = 0;
    cin >> n;
    while (n) {
        cnt += n % 2;
        n /= 2;
    }
    cout << cnt << '\n';
}

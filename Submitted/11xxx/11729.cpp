#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int to, int temp) {
    if (n == 1) cout << from << ' ' << to << '\n';
    else {
        hanoi(n-1, from, temp, to);
        cout << from << ' ' << to << '\n';
        hanoi(n-1, temp, to, from);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << (int)pow(2, n)-1 << '\n';
    hanoi(n, 1, 3, 2);
    return 0;
}
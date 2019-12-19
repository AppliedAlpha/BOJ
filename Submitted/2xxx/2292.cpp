#include <iostream>
using namespace std;
int a, b, c;
// n번째 최대 수: 3n(n-1)+1

int solve(int a) {
    if (a == 1) return 1;
    else for (int n=2; ; n++) if (a <= 3*n*(n-1)+1 && a > 3*(n-1)*(n-2)+1) return n;
}

int main() {
    cin >> a;
    cout << solve(a);
}
#include <iostream>
typedef long long ll;
using namespace std;

ll solve(int n) {
    ll a = 0, b = 1, c;
    int i = 0;
    while (++i <= n) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n) << '\n';
}

/*
#include <iostream>

int main() {
    int a;
    long long n[92];
    n[0] = 0;
    n[1] = n[2] = 1;
    scanf("%d", &a);
    for (int i=3; i<=a; i++) {
        n[i] = n[i-1] + n[i-2];
    }
    printf("%lld", n[a]);
}
*/
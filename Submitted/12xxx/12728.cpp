#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
ll c[211];
int n, x, res;

/* TRY
 *
 * a = 3+root(5), b = 3-root(5)
 * a+b = 6, ab = 4 --> x^2-6x+4 = 0의 두 해 a, b
 * a^n = 6a^(n-1) + 4a^(n-2), b^n = 6b^(n-1) + 4b^(n-2)
 * a^n + b^n = cn --> cn = 6c(n-1) - 4c(n-2)
 *
 * cn은 항상 정수, b^n < 1이므로 a^n의 정수 부분 세 자리: (cn - 1) % 1000
 *
 * 일반화된 수열 cn을 이용해서 DP, %1000으로 계산한다.
 * +)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    c[1] = 6;
    c[2] = 28;
    for (int i=3; i<=210; i++) {
        c[i] = (c[i-1] * 6 - c[i-2] * 4) + 10000;
        c[i] %= 1000;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        res = (x > 104 ? c[(x-4) % 100 + 4] : c[x]);
        cout << "Case #" << i << ": ";
        cout.width(3);
        cout.fill('0');
        cout << (res + 999) % 1000 << '\n';
    }
    return 0;
}

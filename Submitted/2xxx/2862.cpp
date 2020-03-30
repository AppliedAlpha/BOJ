#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, fibo[80] = {1, 2, };

/* f[n] = n개 있을 때 첫째 턴에 가져가야 할 동전 수
 * f[1] = 1, f[2] = 2, f[3] = 3 ..
 * f[4] = 1 (1 -> 2 -> 1)
 * f[5] = 5 (필패 수이므로 처음에 다 가져가야함)
 * f[6] = 1 (1 -> f[5]가 상대에게 필패 수)
 * f[7] = 2 (f[6]과 동일)
 * f[8] = 8 (필패 수)
 * ...
 * f[피보나치 수] => 필패 수 = 피보나치 수
 * f[not 피보나치 수] => f[n - n보다 작은 피보나치 수] = ...
 *                  => 피보나치 수가 나올 때까지 반복 => 첫턴 수
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=2; i<80; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    int tmp = upper_bound(fibo, fibo+80, n) - (fibo + 1);
    while (fibo[tmp] != n) {
        n -= fibo[tmp];
        tmp = upper_bound(fibo, fibo+80, n) - (fibo + 1);
    }
    cout << n;
}

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll fibo[80] = {1, 2, };

/* ~= 2862
 * f[n] = n개 있을 때 첫째 턴에 가져가야 할 동전 수
 * f[2] = -1, f[3] = -1 ..
 * f[4] = 1 (1 -> 2 -> 1)
 * f[5] = -1 (필패 수이므로 처음에 다 가져가야함)
 * f[6] = 1 (1 -> f[5]가 상대에게 필패 수)
 * f[7] = 2 (f[6]과 동일)
 * f[8] = -1 (필패 수)
 * ...
 * f[피보나치 수] => 필패 수이므로 "-1"
 * f[not 피보나치 수] => f[n - n보다 작은 피보나치 수] = ...
 *                  => 피보나치 수가 나올 때까지 반복 => 첫턴 수
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    int k = n;
    for (int i=2; i<80; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    int tmp = upper_bound(fibo, fibo+80, k) - (fibo + 1);
    while (fibo[tmp] != k) {
        k -= fibo[tmp];
        tmp = upper_bound(fibo, fibo+80, k) - (fibo + 1);
    }
    cout << (n == k ? -1 : k);
}

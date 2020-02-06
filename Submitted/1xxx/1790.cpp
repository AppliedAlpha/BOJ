#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;

//RETRY
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    ll before = 1;
    ll after = 10;
    int i = 1;
    while (true) {
        if (before <= k && k < after) {
            int dist = k - before;
            int plus = dist / i;
            int remain = dist % i;
            int start = pow(10, i - 1);
            start += plus;
            if (start > n) {
                cout << -1;
                return 0;
            }
            deque<int> deq;
            while (start != 0) {
                int remain = start % 10;
                start /= 10;
                deq.push_front(remain);
            }
            cout << deq[remain];
            break;
        }
        before = after;
        after += (i + 1) * 9 * pow(10, i);
        i++;
    }
    return 0;
}
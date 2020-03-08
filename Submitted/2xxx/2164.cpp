#include <iostream>
using namespace std;

/* Originally Queue Problem
   But It Has Regularity...
   1 2 2 4 2 4 6 8 2 ...
*/

int solve(int n) {
    if (n <= 2) return n;
    int m = 2;
    while (2*m <= n) m *= 2;
    return (n == m ? n : (n - m) * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}

//20200105
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) q.push(i);
    while (q.size() > 1) {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front();
}
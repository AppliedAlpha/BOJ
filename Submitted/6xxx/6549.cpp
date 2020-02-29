#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;

//TRY
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n) {
        ll res = 0;
        int histo[100002];
        stack<pii> s;
        for (int i = 0; i < n; i++) cin >> histo[i];
        for (int i = 0; i < n; i++) {
            int idx = i;
            while (!s.empty() && s.top().first > histo[i]) {
                res = max(res, 1LL * (i - s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({histo[i], idx});
        }
        while (!s.empty()) {
            res = max(res, 1LL * (n - s.top().second) * s.top().first);
            s.pop();
        }
        cout << res << '\n';
        cin >> n;
    }
    return 0;
}
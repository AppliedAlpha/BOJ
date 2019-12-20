#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii; //sc, t

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, b, sc, t;
    int res = 0;
    cin >> n;
    stack<pii> s;
    for (int i=0; i<n; i++) {
        cin >> b;
        if (b) {
            cin >> sc >> t;
            if (t > 1) s.push({sc, t-1});
            else res += sc;
        }
        else {
            if (s.empty()) continue;
            else {
                pii tmp = s.top();
                s.pop();
                tmp.second--;
                if (!(tmp.second)) res += tmp.first;
                else s.push(tmp);
            }
        }
    }
    cout << res;
}
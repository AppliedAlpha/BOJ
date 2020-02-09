#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
stack<pii> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        while (true) {
            if (s.empty()) {
                cout << "0 ";
                break;
            }
            else if (s.top().first >= tmp) {
                cout << s.top().second << ' ';
                break;
            }
            else s.pop();
        }
        s.push({tmp, i});
    }
    return 0;
}
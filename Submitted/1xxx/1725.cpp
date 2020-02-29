#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, top, bot, histo[100001];

//TRY
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int res = 0;
    cin >> n;
    for (int i=0; i<n; i++) cin >> histo[i];
    for (int i=0; i<=n; i++) {
        while (!s.empty() && histo[s.top()] > histo[i]) {
            top = s.top();
            s.pop();
            if (s.empty()) bot = i;
            else bot = i - s.top() - 1;
            res = max(res, histo[top] * bot);
        }
        s.push(i);
    }
    cout << res;
    return 0;
}
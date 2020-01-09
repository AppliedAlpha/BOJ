#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, index = 0;
    cin >> n;
    vector<int> v(n);
    vector<char> act;
    stack<int> s;
    for (auto & i : v) cin >> i;
    for (int i=1; i<=n; i++) {
        s.push(i);
        act.push_back('+');
        while (!s.empty() && s.top() == v[index]) {
            s.pop();
            act.push_back('-');
            index++;
        }
    }
    if (!s.empty()) cout << "NO";
    else for (auto i : act) cout << i << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v, res;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    res.resize(n);
    for (auto & i : v) cin >> i;
    s.push(0);
    for (int i=0; i<n; i++) {
        if (s.empty()) s.push(i);
        while (!s.empty() && v[s.top()] < v[i]) {
            res[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        res[s.top()] = -1;
        s.pop();
    }
    for (auto i : res) cout << i << ' ';
    return 0;
}
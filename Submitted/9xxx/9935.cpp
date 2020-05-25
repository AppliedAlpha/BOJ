#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;
typedef pair<char, int> pci;

string str, _exp;
stack<pci> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str >> _exp;
    int next = 0;
    for (auto i : str) {
        if (i == _exp[next]) next++;
        else if (i == _exp[0]) next = 1;
        else next = 0;
        s.push({i, next});
        if (next == _exp.size()) {
            for (int j = 0; j < next; j++) s.pop();
            next = s.empty() ? 0 : s.top().second;
        }
    }
    vector<char> v;
    while (!s.empty()) {
        v.push_back(s.top().first);
        s.pop();
    }
    reverse(v.begin(), v.end());
    if (v.empty()) cout << "FRULA";
    else for (auto i : v) cout << i;
    return 0;
}
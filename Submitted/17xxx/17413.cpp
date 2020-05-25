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
#define elif else if
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

string str;
stack<char> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    bool opened = false;
    getline(cin, str);
    for (auto i : str) {
        if (i == '<') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            opened = true;
            cout << i;
        }
        elif (i == '>') {
            opened = false;
            cout << i;
        }
        elif (opened) cout << i;
        elif (i == ' ') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << i;
        }
        else s.push(i);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    getline(cin, str);
    while (str != ".") {
        stack<char> s;
        bool check = true;
        for (auto i : str) {
            if (i == '(' || i == '[') s.push(i);
            if (i == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else {
                    check = false;
                    break;
                }
            }
            if (i == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else {
                    check = false;
                    break;
                }
            }
        }
        if (!s.empty()) check = false;
        cout << (check ? "yes" : "no");
        endl;
        getline(cin, str);
    }
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    stack<int> sk;
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            sk.push(x);
        }
        else if (str == "pop") {
            if (sk.empty()) cout << -1;
            else {
                cout << sk.top();
                sk.pop();
            }
        }
        else if (str == "size") cout << sk.size();
        else if (str == "empty") cout << sk.empty();
        else if (str == "top") {
            if (sk.empty()) cout << -1;
            else cout << sk.top();
        }
        if (str != "push") cout << '\n';
    }
}
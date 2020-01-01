#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    stack<char> s;
    int cnt = 0;
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '(') s.push('(');
        else {
            s.pop();
            if (str[i-1] == '(') cnt += s.size();
            else cnt++;
        }
    }
    cout << cnt;
}
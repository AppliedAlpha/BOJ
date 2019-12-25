#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> tmp;
            q.push(tmp);
        }
        else if (s == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << int(q.empty()) << '\n';
        }
        else if (s == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (s == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}
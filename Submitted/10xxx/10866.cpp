#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push_front") {
            cin >> tmp;
            d.push_front(tmp);
        }
        else if (s == "push_back") {
            cin >> tmp;
            d.push_back(tmp);
        }
        else if (s == "pop_front") {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (s == "size") {
            cout << d.size() << '\n';
        }
        else if (s == "empty") {
            cout << int(d.empty()) << '\n';
        }
        else if (s == "front") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
        }
        else if (s == "back") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
        }
    }
}
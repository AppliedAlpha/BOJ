#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, cnt = 0;
    stack<int> s;
    cin >> a;
    for (int i=0; i<a; i++) {
        cin >> b;
        if (b) {
            s.push(b);
            cnt += b;
        }
        else {
            cnt -= s.top();
            s.pop();
        }
    }
    cout << cnt;
}
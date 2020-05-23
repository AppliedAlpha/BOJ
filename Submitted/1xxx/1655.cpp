#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> _min;
priority_queue<int, vector<int>> _max;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, temp, a, b;
    cin >> n;
    while (n--) {
        cin >> temp;
        if (_max.size() == 0) {
            _max.push(temp);
        }
        else {
            if (_max.size() > _min.size()) {
                _min.push(temp);
            }
            else _max.push(temp);

            if (_max.top() > _min.top()) {
                a = _max.top();
                b = _min.top();
                _max.pop();
                _min.pop();
                _max.push(b);
                _min.push(a);
            }
        }
        cout << _max.top() << '\n';
    }
    return 0;
}

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp : public binary_function<int, int, bool>
{
    bool operator()(const int& a, const int& b) const {
        if (abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        if (temp != 0) {
            pq.push(temp);
        }
        else {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}

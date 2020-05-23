#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, temp, a, b, res = 0;
    cin >> n;
    while (n--) {
        cin >> temp;
        pq.push(temp);
    }
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        res += a+b;
        pq.push(a+b);
    }
    cout << res;
}

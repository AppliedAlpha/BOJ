#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> pq;

// ~= 1927
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

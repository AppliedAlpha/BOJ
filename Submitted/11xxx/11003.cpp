#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
int n, l, temp;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    for (int i=1; i<=n; i++) {
        cin >> temp;
        pq.push({temp, i});
        while (pq.top().y <= i-l) pq.pop();
        cout << pq.top().x << ' ';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define st first
#define en second
using namespace std;
typedef pair<int, int> time;

vector<time> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].en);
    bool first = true;
    for (const auto & i : v) {
        if (first) {
            first = false;
            continue;
        }
        int top = pq.top();
        if (i.st >= top) pq.pop();
        pq.push(i.en);
    }
    cout << pq.size();
    return 0;
}

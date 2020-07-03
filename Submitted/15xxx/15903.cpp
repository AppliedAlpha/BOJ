#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int n, m, temp;
priority_queue<i64, vector<i64>, greater<i64>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    while (n--) {
        cin >> temp;
        pq.push(temp);
    }
    while (m--) {
        i64 a = pq.top();
        pq.pop();
        i64 b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    i64 res = 0LL;
    while (!pq.empty()) {
        res += (i64)pq.top();
        pq.pop();
    }
    cout << res;
    return 0;
}
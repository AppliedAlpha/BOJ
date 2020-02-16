#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define num first
#define times second
using namespace std;
typedef pair<int, int> pii;
bool notPrime[100001];
vector<bool> visited(1000001);

void era() {
    notPrime[0] = notPrime[1] = true;
    for (int i=2; i<=100000; i++) {
        if (!notPrime[i]) {
            for (int j=i+i; j<=100000; j+=i) {
                notPrime[j] = true;
            }
        }
    }
}

vector<int> get_next(int i) {
    vector<int> res = {i/2, i/3};
    if (i < 1000000) res.push_back(i+1);
    if (i > 0) res.push_back(i-1);
    return res;
}

int solve(int n, int a, int b) {
    bool check = false;
    for (int i=a; i<=b; i++) if (!notPrime[i]) check = true;
    if (!check) return -1;
    fill(visited.begin(), visited.end(), false);
    int res = 0;
    queue<pii> q;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        pii now = q.front();
        int k = now.num;
        visited[k] = true;
        q.pop();
        if ((k >= a && k <= b) && !notPrime[k]) {
            res = now.times;
            break;
        }
        vector<int> next = get_next(k);
        for (auto i : next) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(make_pair(i, now.times+1));
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    era();
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        cout << solve(n, a, b) << '\n';
    }
    return 0;
}
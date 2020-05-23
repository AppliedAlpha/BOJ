#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct time {
    int st, en;
};

vector<time> v;

bool cmp(const time &x, const time &y) {
    if (x.en == y.en) return x.st < y.st;
    return x.en < y.en;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int cur = 0, res = 0;
    for (const auto & i : v) {
        if (cur <= i.st) {
            cur = i.en;
            res++;
        }
    }
    cout << res;
    return 0;
}

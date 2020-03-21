#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, k, a, b, c, temp, sqrtN;
vector<int> v, bucket[320];

// 13537 + Update
// Sqrt Decomposition
void update(int i, int x) {
    auto it = lower_bound(bucket[i / sqrtN].begin(), bucket[i / sqrtN].end(), v[i]);
    v[i] = x;
    *it = x;
    sort(bucket[i / sqrtN].begin(), bucket[i / sqrtN].end());
}

int query(int st, int en, int x) {
    int res = 0;
    while (st % sqrtN && st <= en) {
        if (v[st++] > x) res++;
    }
    while ((en + 1) % sqrtN && st <= en) {
        if (v[en--] > x) res++;
    }
    /*
    for (int i=(st / sqrtN); i <= (en / sqrtN); i++) {
        auto it = upper_bound(bucket[i].begin(), bucket[i].end(), x);
        res += bucket[i].end() - it;
    }
    */
    while (st <= en) {
        auto it = upper_bound(bucket[st/sqrtN].begin(), bucket[st/sqrtN].end(), x);
        res += bucket[st/sqrtN].end() - it;
        st += sqrtN;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sqrtN = sqrt(n);
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> temp;
        v[i] = temp;
        bucket[i / sqrtN].push_back(temp);
    }
    for (int i=0; i<n/sqrtN + 1; i++) sort(bucket[i].begin(), bucket[i].end());
    cin >> m;
    while (m--) {
        cin >> k;
        if (k == 1) {
            cin >> a >> b >> c;
            cout << query(a-1, b-1, c) << '\n';
        }
        else {
            cin >> a >> b;
            update(a-1, b);
        }
    }
    return 0;
}
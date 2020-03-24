#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, a, b, c, d, temp, bucket_size;
vector<int> v, bucket[52]; //Changed Bucket Size: SqrtN (MAX ~= 320) -> 2000?

// ~= 14504
// Sqrt Decomposition
void update(int i, int x) { //Changed Update Algorithm
    int cur = i / bucket_size;
    bucket[cur].erase(lower_bound(bucket[cur].begin(), bucket[cur].end(), v[i]));
    bucket[cur].insert(lower_bound(bucket[cur].begin(), bucket[cur].end(), x), x);
    v[i] = x;
}

int query(int st, int en, int x) { //Changed Query Algorithm
    int res = 0;
    int lb = (st / bucket_size + 1 - (st % bucket_size == 0)) * bucket_size;
    int rb = (en / bucket_size) * bucket_size;
    if (lb < rb) {
        for (int i=st; i<lb; i++) if (v[i] > x) res++;
        for (int i=rb; i<=en; i++) if (v[i] > x) res++;
        for (int i=lb / bucket_size; i<rb/bucket_size; i++) {
            res += (bucket[i].end() - upper_bound(bucket[i].begin(), bucket[i].end(), x));
        }
    }
    else for (int i=st; i<=en; i++) if (v[i] > x) res++;
    /*
    while (st % bucket_size && st <= en) {
        if (v[st++] > x) res++;
    }
    while ((en + 1) % bucket_size && st <= en) {
        if (v[en--] > x) res++;
    }
    while (st <= en) {
        auto it = upper_bound(bucket[st/bucket_size].begin(), bucket[st/bucket_size].end(), x);
        res += bucket[st/bucket_size].end() - it;
        st += bucket_size;
    }
     */
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    bucket_size = 2000;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> temp;
        v[i] = temp;
        bucket[i / bucket_size].push_back(temp);
    }
    for (int i=0; i<n/bucket_size + 1; i++) sort(bucket[i].begin(), bucket[i].end());
    cin >> q;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(b-1, c);
        }
        else {
            cin >> b >> c >> d;
            cout << query(b-1, c-1, d) << '\n';
        }
    }
    return 0;
}
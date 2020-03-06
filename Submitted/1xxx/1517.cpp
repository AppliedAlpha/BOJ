#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> v, v2;

//TRY
ll solve(int start, int end) {
    if (start == end) return 0LL;
    int mid = (start + end) / 2;
    ll res = solve(start, mid) + solve(mid+1, end);

    int i = start, j = mid+1, idx = 0;
    while (i <= mid || j <= end) {
        if (i <= mid && (j > end || v[i] <= v[j]))
            v2[idx++] = v[i++];
        else {
            res += (mid - i + 1) * 1LL;
            v2[idx++] = v[j++];
        }
    }
    for (int k=start; k<=end; k++) v[k] = v2[k - start];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    v.resize(n);
    v2.resize(n);
    for (auto & i : v) cin >> i;
    cout << solve(0, n-1);
    return 0;
}
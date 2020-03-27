#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fen_dist[200001], fen_cnt[200001];
int n, a;

/* input보다 작은 값의 합: (갯수) * input - (합)
 * input보다 큰 값의 합: (합) - input * (갯수)
 * TRY
 */

// Binary Indexed Tree

void update_dist(int i, ll x) {
    while (i <= 200000) {
        fen_dist[i] += x;
        i += (i & -i);
    }
}

void update_cnt(int i, ll x) {
    while (i <= 200000) {
        fen_cnt[i] += x;
        i += (i & -i);
    }
}

ll query_dist(int i) {
    ll temp = 0;
    while (i >= 1) {
        temp += fen_dist[i];
        i -= (i & -i);
    }
    return temp;
}

ll query_cnt(int i) {
    ll temp = 0;
    while (i >= 1) {
        temp += fen_cnt[i];
        i -= (i & -i);
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    ll res = 1LL;
    for (int i=0; i<n; i++) {
        ll temp = 0;
        cin >> a;
        a++;
        if (!i) {
            update_cnt(a, 1);
            update_dist(a, a);
        }
        else {
            temp += query_cnt(a-1) * a - query_dist(a-1); // 작은 것들
            temp %= mod;
            temp += (query_dist(200000) - query_dist(a)) - (query_cnt(200000) - query_cnt(a)) * a; // 큰 것들
            temp %= mod;
            update_cnt(a, 1);
            update_dist(a, a);
            res *= temp;
            res %= mod;
        }
    }
    cout << res % mod;
    return 0;
}
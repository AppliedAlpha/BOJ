#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
vector<int> v;
multiset<int> ms;
auto it = ms.begin();
int n, k, l = 0, r = 0;
ll res = 0;

// ~= 1572
// TRY, Later
void update() {
    if (l > r) {
        it--;
        l--;
        r++;
    }
    if (l + 1 < r) {
        it++;
        l++;
        r--;
    }
}

void ins(int i) {
    ms.insert(i);
    if (ms.size() == 1) it = ms.begin();
    else (*it > i) ? l++ : r++;
    update();
}

void del(int i) {
    (*it <= i) ? r-- : l--;
    if (*it == i) it++;
    ms.erase(ms.lower_bound(i));
    update();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    v.resize(n+1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        ins(v[i]);
        if (k < i) del(v[i-k]);
        if (k <= i) res += *it;
    }
    cout << res;
    return 0;
}
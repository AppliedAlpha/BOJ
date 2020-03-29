#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int seg[500001], v[500001], n, tmp;
map<int, int> m;

// Similar Technic But Not The Same ~= 10090
// Binary Indexed Tree (From 1280.cpp)
// TRY

void update(int i, int x) {
    while (i <= n) {
        seg[i] += x;
        i += (i & -i);
    }
}

ll query(int i) {
    ll sum = 0;
    while (i >= 1) {
        sum += seg[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (!m[v[i]]) m[v[i]]++;
    }
    for (auto & [i, j] : m) m[i] = ++tmp;
    // C++17 structured bindings, how awesome!
    for (int i=0; i<n; i++) {
        v[i] = m[v[i]];
        cout << (i+1) - query(v[i]) << '\n';
        update(v[i], 1);
    }
    return 0;
}
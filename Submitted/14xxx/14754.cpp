#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cassert>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

int x, y;
int a[1001][1001] = {0, };
i64 res = 0LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> front, side;

    cin >> y >> x;

    front.resize(x);
    side.resize(y);

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            cin >> a[i][j];
            res += (i64)a[i][j];
        }
    }

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            side[i] = max(side[i], a[i][j]);
            front[j] = max(front[j], a[i][j]);
        }
    }

    vector<int> sides;
    sides.reserve(front.size() + side.size());
    sides.insert(sides.end(), all(front));
    sides.insert(sides.end(), all(side));
    sort(all(sides));
    sides.erase(unique(all(sides)), sides.end());

    for (auto i : sides) {
        res -= i;
    }
    cout << res;
    return 0;
}
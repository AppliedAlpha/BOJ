#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int v['Z'+1] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        for (int i=str.length() - 1, j=1; i>=0; --i, j *= 10) v[str[i]] += j;
    }
    sort(v + 'A', v + 'Z' + 1);
    int res = 0, val = 10;
    for (char c = 'Z'; c >= 'A'; --c)
        if (v[c] != 0) res += (v[c] * (--val));
    cout << res;
    return 0;
}

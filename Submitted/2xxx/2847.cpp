#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int>::reverse_iterator vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, temp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    if (n == 1) cout << 0;
    else {
        int res = 0;
        int last = v[n-1];
        for (vi = v.rbegin() + 1; vi < v.rend(); vi++) {
            if (last <= *vi) {
                res += *vi - last + 1;
                *vi = last - 1;
            }
            last = *vi;
        }
        cout << res;
    }
    return 0;
}

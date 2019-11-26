#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, t[1002] = {0, }, bs;
    long long cnt = 0l;
    cin >> n;
    for (int i=0; i<n; i++) cin >> t[i];
    cin >> bs;
    for (int i=0; i<n; i++) {
        if (t[i] == 0) continue;
        if (t[i] % bs == 0) cnt += t[i];
        else cnt += (t[i]/bs+1)*bs;
    }
    cout << cnt;
}
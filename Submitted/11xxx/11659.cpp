#include <iostream>
using namespace std;
int arr[100002], sum[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    sum[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        sum[i] = arr[i] + sum[i-1];
    }
    while (m--) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
    return 0;
}
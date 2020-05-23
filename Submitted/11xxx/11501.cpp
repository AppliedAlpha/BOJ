#include <iostream>
using namespace std;
typedef long long ll;
ll day[1000003];
int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> day[i];
        ll maxDay = 0;
        ll income = 0;
        for (int i=n-1; i>=0; i--) {
            if (maxDay < day[i]) maxDay = day[i];
            if (maxDay > day[i]) income += (maxDay - day[i]);
        }
        cout << income << '\n';
    }
    return 0;
}

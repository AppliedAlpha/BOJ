#include <iostream>
using namespace std;

int n, k, sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> k;
        sum += k;
    }
    cout << "Junhee is " << (sum*2 >= n ? "" : "not ") << "cute!";
    return 0;
}
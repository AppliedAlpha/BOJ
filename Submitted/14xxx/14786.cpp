#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;

//TRY
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, cnt = 50000;
    cin >> a >> b >> c;
    ld _min = (c-b)/(ld)a, _max = (c+b)/(ld)a, mid;
    while (_min < _max && cnt--) {
        mid = (_min + _max) / 2;
        if (mid > (c-(b*(ld)sin(mid)))/a)
            _max = mid;
        else if (mid < (c-(b*(ld)sin(mid)))/a)
            _min = mid + 0.00000000000000000001;
    }
    cout << fixed << setprecision(19);
    cout << mid + 0.00000000000000000005;
    return 0;
}
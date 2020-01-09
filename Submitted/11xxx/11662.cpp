#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<double,double> pdd;
int a[2], b[2], c[2], d[2];

pdd minho(double p) {
    return {a[0]+(b[0]-a[0])*(p/100), a[1]+(b[1]-a[1])*(p/100)};
}

pdd kangho(double p) {
    return {c[0]+(d[0]-c[0])*(p/100), c[1]+(d[1]-c[1])*(p/100)};
}

double value(double p) {
    pdd m = minho(p);
    pdd k = kangho(p);
    return (k.x-m.x)*(k.x-m.x)+(k.y-m.y)*(k.y-m.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
    double start = 0.0, end = 100.0, ans = 2e9;
    while (end - start >= 1e-10) {
        double left = (start*2+end)/3;
        double right = (start+end*2)/3;
        ans = min(ans, min(value(left), value(right)));
        if (value(left) >= value(right)) start = left;
        else end = right;
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << sqrt(ans);
}
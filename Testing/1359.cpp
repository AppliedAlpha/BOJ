#include <iostream>
using namespace std;

int main() {
    int n, m, k, r = 1;
    cin >> n >> m >> k;
    for (int i=m; i>=m-k+1; i--) r *= i;
    double rr = r;
    for (int i=n; i>=n-k+1; i--) rr /= i;
    printf("%.15lf", rr);
}
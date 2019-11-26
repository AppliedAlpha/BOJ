#include <iostream>
#include <cmath>
using namespace std;
struct answer {
    int cnt, min;
};

answer solve(int m, int n) {
    int cnt = 0, min = 2147483646;
    int mm = (int) sqrt(m);
    int nn = (int) sqrt(n);
    if (mm == nn) {
        if (mm * mm == m) return {m, m};
        else return {-1, 0};
    }
    else {
        for (int i=mm; i<=nn; i++) {
            if (i*i <= n && i*i >= m) {
                cnt += i*i;
                if (i*i <= min) min = i*i;
            }
        }
        return {cnt, min};
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    answer a = solve(m, n);
    cout << a.cnt << '\n';
    if (a.min) cout << a.min;
}
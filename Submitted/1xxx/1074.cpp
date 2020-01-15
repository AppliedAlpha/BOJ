#include <iostream>
#include <cmath>
using namespace std;
int R, C, res = 0;

void split(int n, int r, int c) {
    if (n == 2) {
        if (r == R && c == C) {
            cout << res;
            return;
        }
        res++;
        if (r == R && c+1 == C) {
            cout << res;
            return;
        }
        res++;
        if (r+1 == R && c == C) {
            cout << res;
            return;
        }
        res++;
        if (r+1 == R && c+1 == C) {
            cout << res;
            return;
        }
        res++;
        return;
    }
    split(n/2, r, c);
    split(n/2, r, c+n/2);
    split(n/2, r+n/2, c);
    split(n/2, r+n/2, c+n/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> R >> C;
    split((int)pow(2, n), 0, 0);
    return 0;
}
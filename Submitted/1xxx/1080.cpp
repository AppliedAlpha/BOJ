#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char a[53][53], b[53][53];
int x, y, res = 0;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    cin >> y >> x;
    for (int i=0; i<y; i++) scanf("%s", a[i]);
    for (int i=0; i<y; i++) scanf("%s", b[i]);
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            a[i][j] -= '0';
            b[i][j] -= '0';
        }
    }
    for (int i=0; i<y-2; i++) {
        for (int j=0; j<x-2; j++) {
            if (a[i][j] == b[i][j]) continue;
            else {
                for (int k=0; k<3; k++) for (int l=0; l<3; l++) a[i+k][j+l] = !(a[i+k][j+l]);
                res++;
            }
        }
    }
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (a[i][j] != b[i][j]) res = -1;
        }
    }
    cout << res;
    return 0;
}

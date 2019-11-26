#include <iostream>
using namespace std;

int main() {
    int c;
    int ta[6][2] = {{1, 500}, {3, 300}, {6, 200}, {10, 50}, {15, 30}, {21, 10}};
    int tb[5][2] = {{1, 512}, {3, 256}, {7, 128}, {15, 64}, {31, 32}};
    cin >> c;
    for (int i=1; i<=c; i++) {
        int a, b, t = 0;
        cin >> a >> b;
        if (a<1 || a>21) a = 0;
        if (b<1 || b>31) b = 0;
        for (auto & j : ta) {
            if (a == 0) break;
            if (a <= j[0]) {
                t += j[1];
                break;
            }
        }
        for (auto & j : tb) {
            if (b == 0) break;
            if (b <= j[0]) {
                t += j[1];
                break;
            }
        }
        cout << t*10000 << "\n";
    }
}
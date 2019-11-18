#include <iostream>
#include <cmath>
using namespace std;
string nm, gr;

int main() {
    int n, t, sc = 0;
    double sum = 0l, grr;
    cin >> n;
    for (int i=0; i<n; i++) {
        grr = 0;
        cin >> nm >> t >> gr;
        if (gr[0] != 'F') {
            switch (gr[0]) {
                case 'A': grr += 4; break;
                case 'B': grr += 3; break;
                case 'C': grr += 2; break;
                case 'D': grr += 1; break;
                default: break;
            }
            switch (gr[1]) {
                case '+': grr += 0.3; break;
                case '-': grr -= 0.3; break;
                default: break;
            }
        }
        sum += grr * t;
        sc += t;
    }
    double c = round((sum/sc) * 100) / 100;
    printf("%.02lf", c);
}
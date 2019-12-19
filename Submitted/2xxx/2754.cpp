#include <iostream>
using namespace std;
string gr;

int main() {
    double grr = 0l;
    cin >> gr;
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
    printf("%.01lf", grr);
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r, w, l, i = 1;
    cin >> r;
    while (r) {
        cin >> w >> l;
        int t = (int)(pow(w, 2) + pow(l, 2));
        cout << "Pizza " << i << " ";
        cout << ((int)pow(r*2, 2) >= t ? "fits " : "does not fit ");
        cout << "on the table.\n";
        i++;
        cin >> r;
    }
}
#include <iostream>
using namespace std;

double fact(int i) {
    int k = 1;
    for (int j=2; j<=i; j++) k *= j;
    return k;
}

int main() {
    int n;
    double e = 2.5f;
    cout << "n e\n- -----------\n0 1\n1 2\n2 2.5\n";
    cout.setf(ios::showpoint);
    cout.precision(10);
    for (int i=3; i<10; i++) {
        e += 1/fact(i);
        cout << i << ' ' << e << '\n';
    }
}
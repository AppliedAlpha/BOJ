#include <iostream>
using namespace std;
int t[42] = {0, }, n, c = 0;

int main() {
    for (int i=0; i<10; i++) {
        cin >> n;
        t[n % 42]++;
    }
    for (int i : t) if (i) c++;
    cout << c;
}
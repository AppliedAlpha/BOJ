#include <iostream>
using namespace std;
int n, t, i;

int main() {
    cin >> n;
    int a[2] = {n/10, n%10};
    while (true) {
        i++;
        t = a[0] + a[1];
        a[0] = a[1];
        a[1] = t % 10;
        if (a[0] == n/10 && a[1] == n%10) break;
    }
    cout << i;
}
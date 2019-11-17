#include <iostream>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    a = a - 99 * (a/100 - a%10);
    b = b - 99 * (b/100 - b%10);
    cout << ((a > b) ? a : b);
}
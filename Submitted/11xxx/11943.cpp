#include <iostream>
using namespace std;
int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    cout << ((a + d <= b + c) ? a + d : b + c);
}
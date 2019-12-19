#include <iostream>
using namespace std;
int main() {
    int a, x, y;
    cin >> a;
    for (int i=1; i<=a; i++) {
        cin >> x >> y;
        printf("Case #%d: %d + %d = %d\n", i, x, y, x+y);
    }
}
#include <iostream>
using namespace std;
int a, b, c;

int main() {
    cin >> a >> b >> c;
    while (a && b && c) {
        if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
            cout << "right";
        else cout << "wrong";
        cout << "\n";
        cin >> a >> b >> c;
    }
}
#include <iostream>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    while (a && b) {
        if (b / a > 1 && !(b % a)) cout << "factor";
        else if (a / b > 1 && !(a % b)) cout << "multiple";
        else cout << "neither";
        cout << "\n";
        cin >> a >> b;
    }
}
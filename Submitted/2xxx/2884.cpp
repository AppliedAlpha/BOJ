#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = (a*60+b+1395) % 1440;
    cout << c / 60 << " " << c % 60;
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c, s = 0;
    cin >> a >> b >> c;
    for (int i=1; i<=a; i++) s += i*b + i*i*c;
    cout << s;
    return 0;
}

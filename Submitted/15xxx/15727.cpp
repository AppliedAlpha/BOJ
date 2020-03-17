#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a;
    cin >> a;
    cout << a/5 + (a % 5 != 0);
    return 0;
}
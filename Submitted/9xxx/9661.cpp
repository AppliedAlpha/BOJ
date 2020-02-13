#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    bool a[5] = {0, 1, 0, 1, 1};
    cin >> n;
    cout << (a[n % 5] ? "SK" : "CY");
    return 0;
}
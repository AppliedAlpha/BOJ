#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    bool a[7] = {1, 0, 1, 1, 1, 1, 0};
    cin >> n;
    cout << (a[(n-1) % 7] ? "SK" : "CY");
    return 0;
}
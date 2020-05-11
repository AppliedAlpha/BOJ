#include <iostream>
using namespace std;

int solve(int n) {
    int arr[21] = {0, -1, 1, -1, 2, 1, 3, 2, 4, 3, 2, 4, 3, 5, 4, 3, 5, 4, 6, 5, 4};
    if (n <= 20) return arr[n];
    else return 2*(n/10 - 1) + arr[10 + n%10];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}
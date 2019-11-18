#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (long long)(n+1) * n * (n-1) / 2;
}
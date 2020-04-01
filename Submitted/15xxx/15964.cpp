#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b;
    cout << (a+b)*(a-b);
    return 0;
}
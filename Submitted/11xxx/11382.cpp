#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long a, sum = 0LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin >> a) sum += a;
    cout << sum;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin >> n) sum += n;
    cout << sum;
    return 0;
}
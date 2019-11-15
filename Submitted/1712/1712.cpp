#include <iostream>
using namespace std;
int a, b, c;
// 순수익 c-b가 a보다 커지면 수익이 발생

int solve(int a, int b, int c) {
    if (b >= c) return -1;
    else return (a/(c-b))+1;
}

int main() {
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}
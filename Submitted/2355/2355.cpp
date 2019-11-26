#include <iostream>
using namespace std;

long long solve(long long a, long long b) {
    if (a >= 0 && b >= 0) return (b*(b+1)-a*(a-1))/2;
    else if (a < 0 && b >= 0) return (b*(b+1)-(0-a)*((0-a)+1))/2;
    else return 0-((0-a)*((0-a)+1)-(0-b)*((0-b)-1))/2;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << solve(a, b);
}
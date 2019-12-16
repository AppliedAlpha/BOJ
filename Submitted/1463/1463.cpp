#include <iostream>
#include <vector>
#define INF 2147483646
using namespace std;
vector<int> value;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int n) {
    value.resize(n+1);
    value[1] = 0;
    for (int i=2; i<=n; i++) {
        value[i] = INF;
        if (!(i%6))
            value[i] = min(min(value[i], value[i-1]+1), min(value[i/2], value[i/3])+1);
        else if (!(i%2))
            value[i] = min(value[i], (min(value[i/2], value[i-1])+1));
        else if (!(i%3))
            value[i] = min(value[i], min(value[i/3], value[i-1])+1);
        else value[i] = min(value[i], value[i-1]+1);
    }
    return value[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << solve(n) << '\n';
    //for (auto c : value) cout << c << " | ";
}
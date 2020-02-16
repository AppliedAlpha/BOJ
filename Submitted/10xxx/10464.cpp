#include <iostream>
using namespace std;
int brute[8] = {0, 1, 3, 0, 4, 1, 7, 0};

//TRY
int solve(int x) {
    if (x <= 7) return brute[x];
    int lead = 0;
    while ((1 << lead) < x) lead++;
    lead--;
    if (x & 1) return solve(x ^ (1 << lead));
    else return (1 << lead) ^ solve(x ^ (1 << lead));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, s, f;
    cin >> t;
    while (t--) {
        cin >> s >> f;
        cout << (solve(f) ^ solve(s-1)) << '\n';
    }
}
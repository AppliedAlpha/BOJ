#include <iostream>
#include <string>
#include <map>
using namespace std;
int p, idx, m;
bool notPrime[10001];

// Sieve
void sieve() {
    notPrime[0] = notPrime[1] = true;
    for (int i=2; i*i<=10000; i++) {
        if (!notPrime[i]) for (int j=i*i; j<=10000; j+=i) notPrime[j] = true;
    }
}

bool solve(int n) {
    if (notPrime[n]) return false;
    map<int, bool> visited;
    while (n != 1) {
        int tmp = 0;
        string str = to_string(n);
        for (int i=0; i<str.size(); i++) tmp += (str[i]-'0') * (str[i]-'0');
        if (visited[tmp]) return false;
        visited[tmp] = true;
        n = tmp;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    cin >> p;
    while (p--) {
        cin >> idx >> m;
        cout << idx << ' ' << m << ' ' << (solve(m) ? "YES" : "NO") << '\n';
    }
    return 0;
}

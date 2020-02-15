#include <iostream>
#include <vector>
using namespace std;
bool notPrime[4000001];
vector<int> primes;

void era() {
    notPrime[0] = notPrime[1] = true;
    for (int i=2; i<=4000000; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=4000000; j+=i) {
                notPrime[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cnt = 0;
    era();
    cin >> n;
    for (int i=0; i<primes.size(); i++) {
        if (n < primes[i]) break;
        int tmp = i, sum = 0;
        while (sum < n && tmp < primes.size())
            sum += primes[tmp++];
        if (sum == n) cnt++;
    }
    cout << cnt;
    return 0;
}
#include <iostream>
using namespace std;
int minFactor[5000001];

void era() {
    minFactor[0] = minFactor[1] = -1;
    for (int i=2; i<=5000000; i++) minFactor[i] = i;
    for (int i=2; i*i<=5000000; i++) {
        if (minFactor[i] == i) {
            for (int j=i*i; j<=5000000; j+=i) {
                if (minFactor[j] == j) minFactor[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    era();
    cin >> n;
    while (n--) {
        cin >> m;
        while (m > 1) {
            cout << minFactor[m] << ' ';
            m /= minFactor[m];
        }
        cout << '\n';
    }
    return 0;
}
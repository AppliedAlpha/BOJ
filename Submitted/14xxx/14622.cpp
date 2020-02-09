#include <iostream>
#include <vector>
#include <algorithm>
#define dae false
#define kyu true
using namespace std;
long long dscore = 0, kscore = 0;
vector<int> dBig, kBig;
bool notPrime[5000001];
int called[5000001]; //0=안 부름 1=d 2=k

void era() {
    notPrime[0] = notPrime[1] = true;
    for (int i=2; i*i<=5000000; i++) {
        if (!notPrime[i]) {
            for (int j=i*i; j<=5000000; j+=i) {
                notPrime[j] = true;
            }
        }
    }
}

void play(int num, bool player) {
    if (notPrime[num]) {
        if (player == dae) {
            if (kBig.size() <= 2) kscore += 1000;
            else kscore += kBig[0];
        }
        else {
            if (dBig.size() <= 2) dscore += 1000;
            else dscore += dBig[0];
        }
    }
    else if (called[num]) {
        if (player == dae) dscore -= 1000;
        else kscore -= 1000;
    }
    else {
        if (player == dae) {
            dBig.insert(lower_bound(dBig.begin(),dBig.end(), num), num);
            if (dBig.size() > 3) dBig.erase(dBig.begin());
            called[num] = 1;
        }
        else {
            kBig.insert(lower_bound(kBig.begin(),kBig.end(), num), num);
            if (kBig.size() > 3) kBig.erase(kBig.begin());
            called[num] = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, k;
    era();
    cin >> n;
    while (n--) {
        cin >> d >> k;
        play(d, dae);
        play(k, kyu);
    }
    if (dscore > kscore) cout << "소수의 신 갓대웅";
    else if (dscore < kscore) cout << "소수 마스터 갓규성";
    else cout << "우열을 가릴 수 없음";
    return 0;
}
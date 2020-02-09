#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> pelin;
bool check[10001];

void make_pelin(int n) {
    string s = to_string(n);
    string copy = s;
    copy.pop_back();
    reverse(copy.begin(), copy.end());
    string p = s;
    reverse(p.begin(), p.end());
    string rev = s;
    if (s.length() == 1) {
        pelin.push_back(n);
        pelin.push_back(stoi(s + s));
    }
    else {
        pelin.push_back(stoi(s + p));
        pelin.push_back(stoi(s + copy));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i=1; i<=10000; i++) make_pelin(i);
    sort(pelin.begin(), pelin.end());
    int a, b;
    cin >> a >> b;
    check[1] = true;
    for (int i=2; i<=10000; i++) {
        if (check[i]) continue;
        for (int j=2*i; j<=10000; j+=i) check[j] = true;
    }
    for (int i=0; i<pelin.size() - 2; i++) {
        bool ok = false;
        if (pelin[i] >= a && pelin[i] <= b) {
            for (int j=1; j*j<=pelin[i]; j++) {
                if (!check[j] && !(pelin[i] % j)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) cout << pelin[i] << '\n';
        }
    }
    cout << "-1";
    return 0;
}
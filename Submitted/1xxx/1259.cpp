#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    while (s != "0") {
        bool res;
        for (int i=0; i<(s.size()+1)/2; i++) {
            if (s[i] != s[s.size()-i-1]) {
                res = false;
                goto c;
            }
        }
        res = true;
        c:
        cout << (res ? "yes\n" : "no\n");
        cin >> s;
    }
    return 0;
}
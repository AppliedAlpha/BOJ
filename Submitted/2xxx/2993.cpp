#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str, res;
    cin >> str; //0 ~ len-1
    res = str;
    int n = str.size();
    for (int i=0; i<n-1; i++) {
        for (int j=i; j<n-1; j++) {
            if (i >= j) continue;
            string sp[3];
            for (int k=0; k<=i; k++) sp[0] += str[k]; //0, i
            for (int k=i+1; k<=j; k++) sp[1] += str[k]; //i+1, j
            for (int k=j+1; k<n; k++) sp[2] += str[k]; //j+1, len-1
            for (auto & k : sp) reverse(k.begin(), k.end());
            res = min(res, sp[0]+sp[1]+sp[2]);
        }
    }
    cout << res;
    return 0;
}
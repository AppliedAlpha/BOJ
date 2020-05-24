#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
#define endl cout << '\n'
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    if (str.length() < 3) cout << "0\n0";
    else {
        int joi = 0, ioi = 0;
        for (int i=0; i<str.length()-2; i++) {
            auto sub = str.substr(i, 3);
            if (sub == "JOI") joi++;
            else if (sub == "IOI") ioi++;
        }
        cout << joi << '\n' << ioi;
    }
    return 0;
}
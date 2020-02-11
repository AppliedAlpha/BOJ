#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int dp[1002][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;
    for (int i=0; i<a.length(); i++) {
        for (int j=0; j<b.length(); j++) {
            if (i == 0) dp[i][j] = 0;
            else if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string LCS;
    auto LCS_len = dp[a.length()-1][b.length()-1];
    auto j_pt = b.length()-1;
    cout << LCS_len << '\n';
    for (int i=a.length()-1; i>0; i--) {
        for (int j=j_pt; j>0; j--) {
            if (dp[i][j] == LCS_len && dp[i-1][j-1] == LCS_len-1) {
                if (dp[i-1][j] == LCS_len-1 && dp[i][j-1] == LCS_len-1) {
                    LCS_len--;
                    LCS = a[i] + LCS;
                    j_pt = j;
                    break;
                }
            }
        }
    }
    cout << LCS;
    return 0;
}
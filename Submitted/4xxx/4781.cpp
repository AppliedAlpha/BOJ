#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10001]; //100.00

int main() {
    int n, money, money2;
    scanf("%d %d.%2d", &n, &money, &money2);
    while (n) {
        memset(dp, 0, sizeof(dp));
        money = money * 100 + money2;
        int res = 0;
        while (n--) {
            int c, mt, mt2;
            scanf("%d %d.%2d", &c, &mt, &mt2);
            mt = mt * 100 + mt2;
            for (int i=mt; i<=money; i++) {
                dp[i] = max(dp[i], dp[i-mt]+c);
                res = max(res, dp[i]);
            }
        }
        printf("%d\n", dp[money]);
        scanf("%d %d.%2d", &n, &money, &money2);
    }
}
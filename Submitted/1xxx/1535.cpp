#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000009
#define endl cout << '\n'
using namespace std;
typedef long long i64;

vector<int> price;
vector<int> profit;
vector<vector<int>> value(21, vector<int>(100, 0));

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    price.resize(n);
    profit.resize(n);
    for (auto & i : price) cin >> i;
    for (auto & i : profit) cin >> i;

    for (int i=0; i<=99; i++) {
        if (price[0] <= i) value[0][i] = profit[0];
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<=99; j++) {
            if (j-price[i] >= 0) {
                value[i][j] = max(profit[i] + value[i-1][j-price[i]], value[i-1][j]);
            }
            else value[i][j] = value[i-1][j];
        }
    }
    cout << value[n-1][99];
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> price;
vector<int> profit;
vector<vector<int>> value(101, vector<int>(10001, 0));

int main() { // ~= 12865
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, lim;
    cin >> n >> lim;
    price.resize(n);
    profit.resize(n);
    for (int i=0; i<n; i++) cin >> price[i] >> profit[i];
    for (int i=0; i<=lim; i++) {
        if (price[0] <= i) value[0][i] = profit[0];
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<=lim; j++) {
            if (j-price[i] >= 0) {
                value[i][j] = max(profit[i] + value[i-1][j-price[i]], value[i-1][j]);
            }
            else value[i][j] = value[i-1][j];
        }
    }
    cout << value[n-1][lim];
    return 0;
}
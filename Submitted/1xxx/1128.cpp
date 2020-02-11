#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define _price first
#define _profit second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> prs;
vector<ll> total_price(51), total_profit(51);
ll max_price, max_profit = 0;

//LETS TRY

bool comp(const pll &a, const pll &b) {
    if (a._price != b._price) return a._price > b._price;
    else return a._profit > b._profit;
}

void solve(ll profit, ll price, int i, bool check) {
    max_profit = max(max_profit, profit);
    if (price >= total_price[i]) {
        ll tmp = profit + total_profit[i];
        max_profit = max(max_profit, tmp);
        return;
    }
    if (check && prs[i]._price == prs[i-1]._price) {
        solve(profit, price, i+1, check);
        return;
    }
    if (price - prs[i]._price >= 0) solve(profit + prs[i]._profit, price - prs[i]._price, i+1, false);
    solve(profit, price, i+1, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        prs.emplace_back(a, b);
    }
    cin >> max_price;
    sort(prs.begin(), prs.end(), comp);
    total_price[n-1] = prs[n-1]._price;
    total_profit[n-1] = prs[n-1]._profit;
    for (int i=n-2; i>=0; i--) {
        total_price[i] = total_price[i+1] + prs[i]._price;
        total_profit[i] = total_profit[i+1] + prs[i]._profit;
    }
    solve(0, max_price, 0, false);
    cout << max_profit;
    return 0;
}
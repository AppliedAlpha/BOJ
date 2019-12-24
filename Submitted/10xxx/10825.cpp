#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct s {
    string name;
    int k, e, m;
};
vector<s> v;

bool comp(const s &a, const s &b) {
    if (a.k != b.k) return a.k > b.k;
    else if (a.e != b.e) return a.e < b.e;
    else if (a.m != b.m) return a.m > b.m;
    else return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    string x;
    cin >> n;
    while (n--) {
        cin >> x >> a >> b >> c;
        v.push_back({x, a, b, c});
    }
    sort(v.begin(), v.end(), comp);
    for (const auto &i : v) cout << i.name << '\n';
}
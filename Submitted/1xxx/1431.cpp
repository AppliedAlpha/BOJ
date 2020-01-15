#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        int sa = 0, sb = 0;
        for (auto i : a) if (i >= '1' && i <= '9') sa += i-'0';
        for (auto i : b) if (i >= '1' && i <= '9') sb += i-'0';
        if (sa != sb) return sa < sb;
        else return a < b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> str(n);
    for (auto & i : str) cin >> i;
    sort(str.begin(), str.end(), comp);
    for (const auto& i : str) cout << i << '\n';
    return 0;
}
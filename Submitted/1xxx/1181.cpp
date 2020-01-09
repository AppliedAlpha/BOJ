#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto & i : v) cin >> i;
    sort(v.begin(), v.end(), compare);
    cout << v[0] << '\n';
    for (int i=1; i<n; i++) {
        if (v[i] != v[i-1]) cout << v[i] << '\n';
    }
}
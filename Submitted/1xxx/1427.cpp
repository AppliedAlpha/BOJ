#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    for (auto i : str) v.emplace_back(i-'0');
    sort(v.rbegin(), v.rend());
    for (auto i : v) cout << i;
}
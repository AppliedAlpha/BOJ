#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    vector<string> v;
    cin >> str;
    for (int i=0; i<str.size(); i++) {
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for (const auto &a : v) cout << a << '\n';
}
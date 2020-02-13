#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i = 1;
    string str;
    cin >> n;
    while (n) {
        cout << i++ << '\n';
        v.clear();
        for (int j=0; j<n+1; j++) {
            getline(cin, str);
            v.push_back(str);
        }
        v.erase(v.begin());
        sort(v.begin(), v.end());
        for (auto m : v) cout << ((m != "\n") ? m : "") << '\n';
        cin >> n;
    }
    return 0;
}
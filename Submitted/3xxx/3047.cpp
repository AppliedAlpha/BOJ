#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    string str;
    cin >> v[0] >> v[1] >> v[2] >> str;
    sort(v.begin(), v.end());
    for (auto i : str) {
        if (i == 'A') cout << v[0];
        if (i == 'B') cout << v[1];
        if (i == 'C') cout << v[2];
        cout << ' ';
    }
    return 0;
}
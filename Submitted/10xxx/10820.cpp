#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s, '\n')) {
        vector<int> v(4, 0);
        for (auto a : s) {
            if (a >= 'a' && a <= 'z') v[0]++;
            else if (a >= 'A' && a <= 'Z') v[1]++;
            else if (a >= '0' && a <= '9') v[2]++;
            else if (a == ' ') v[3]++;
        }
        for (auto b : v) cout << b << ' ';
        cout << '\n';
    }
}
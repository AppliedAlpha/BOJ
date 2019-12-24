#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp, m;
    cin >> n;
    vector<int> v;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    m = v[0];
    for (int i=1; i<v.size(); i++) {
        if (v[i-1] > 0 && v[i] + v[i-1] > 0) {
            v[i] += v[i-1];
        }
        if (m < v[i]) {
            m = v[i];
        }
    }
    cout << m << '\n';
}
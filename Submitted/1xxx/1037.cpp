#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp, max = 2, min = 1000001;
    cin >> n;
    while (n--) {
        cin >> tmp;
        if (tmp >= max) max = tmp;
        if (tmp <= min) min = tmp;
    }
    cout << max*min;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    cin >> n;
    int m = n;
    vector<int> v;
    while (m--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout << v[0]*v[n-1];
}
*/
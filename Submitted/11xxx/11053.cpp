#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> len(1000, 1);
vector<int> arr(1000, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, _max = 1;
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int k=0; k<n; k++) {
        for (int i=0; i<k; i++) {
            if (arr[i] < arr[k]) {
                len[k] = max(len[k], len[i]+1);
                _max = max(_max, len[k]);
            }
        }
    }
    cout << _max;
}
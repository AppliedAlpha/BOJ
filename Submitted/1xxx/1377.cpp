#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> num[500003]; //num, original index

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num[i].first;
        num[i].second = i;
    }
    sort(num, num+n);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt = max(cnt, num[i].second-i); //가장 멀리 온 사람
    }
    cout << ++cnt;
}
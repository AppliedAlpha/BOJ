#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i=0; i<6; i++) {
        cin >> n;
        cout << (i < 2 ? (1-n) : (i != 5 ? (2-n) : (8-n))) << ' ';
    }
    return 0;
}
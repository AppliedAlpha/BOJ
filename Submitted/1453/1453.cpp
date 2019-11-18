#include <iostream>
using namespace std;
bool a[101];

int main() {
    int n, t, c = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        if (a[t]) c++;
        else a[t] = true;
    }
    cout << c;
}
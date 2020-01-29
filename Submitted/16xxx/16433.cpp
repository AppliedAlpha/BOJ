#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    int c = (a+b)%2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << ((i+j)%2 == c ? 'v' : '.');
        }
        cout << '\n';
    }
}
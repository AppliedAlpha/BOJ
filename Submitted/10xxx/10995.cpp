#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i%2) {
            for (int j=1; j<=n; j++) {
                if (j == n) cout << '*';
                else cout << "* ";
            }
        }
        else for (int j=1; j<=n; j++) cout << " *";
        cout << '\n';
    }
    return 0;
}
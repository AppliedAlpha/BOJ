#include <iostream>
using namespace std;
char a[101][101];

int main() {
    int n, m;
    cin >> n;
    for (int i=0; i<n; i++) scanf("%s", a[i]);
    cin >> m;
    if (m == 1) for (int i=0; i<n; i++) printf("%s\n", a[i]);
    else if (m == 2) {
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=0; j--) cout << a[i][j];
            cout << "\n";
        }
    }
    else for (int i=n-1; i>=0; i--) printf("%s\n", a[i]);
}
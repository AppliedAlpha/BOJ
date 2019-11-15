#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        char a[53];
        int l = 0;
        int r = 0;
        scanf("%s", a);
        for (int j=0; a[j] != NULL; j++) {
            if (a[j] == '(') l++;
            else if (a[j] == ')') r++;
            if (l < r) break;
        }
        cout << ((l == r) ? "YES" : "NO") << endl;
    }
    return 0;
}
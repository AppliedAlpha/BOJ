#include <iostream>
using namespace std;
char str[51];

int main() {
    int n, l=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> str[i];
        if (str[i] == 'L') l++;
    }
    cout << (l >= 4 ? n-(l/2-1) : n);
}
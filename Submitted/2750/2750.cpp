#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    vector<short int> v;
    int c;
    short int s;
    cin >> c;
    v.resize(c);
    for (int i=0; i<c; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (auto a : v) cout << a << '\n';
    return 0;
}

/*
#include <stdio.h>
int main() {
    int a, i, j, b[1000], temp=0;
    scanf("%d", &a);
    for (i=0; i<a; i++) scanf("%d", &b[i]);
    for (i=0; i<a; i++) {
        for (j=0; j<i; j++) {
            if (b[j] > b[i]) {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
    for (i=0; i<a; i++) printf("%d\n", b[i]);
}
*/
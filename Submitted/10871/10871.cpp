#include <iostream>

int main() {
    int n, x, a[10003];
    scanf("%d %d", &n, &x);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < x) printf("%d ", a[i]);
    }
    return 0;
}

#include <iostream>

int main() {
    int a;
    long long n[92];
    n[0] = 0;
    n[1] = n[2] = 1;
    scanf("%d", &a);
    for (int i=3; i<=a; i++) {
        n[i] = n[i-1] + n[i-2];
    }
    printf("%lld", n[a]);
}
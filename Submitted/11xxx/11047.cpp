#include <iostream>

int main() {
    int a, b, sum = 0, n[10]={0, };
    scanf("%d %d", &a, &b);
    for (int i=0; i<a; i++) {
        scanf("%d", &n[i]);
    }
    for (int i=a-1; i>=0; i--) {
        if (b/n[i] == 0) continue;
        sum += b/n[i];
        b = b%n[i];
    }
    printf("%d", sum);
    return 0;
}
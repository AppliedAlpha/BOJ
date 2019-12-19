#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a || b) {
        printf("%d\n", a+b);
        scanf("%d %d", &a, &b);
    }
    return 0;
}
#include <iostream>
int main() {
    int a, x, y;
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x+y);
    }
}
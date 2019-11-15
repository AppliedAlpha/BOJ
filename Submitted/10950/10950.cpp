#include <iostream>
int main() {
    int n[1000];
    int a, x, y;
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
        scanf("%d %d", &x, &y);
        n[i] = x+y;
    }
    for (int i=0; i<a; i++) printf("%d\n", n[i]);
}
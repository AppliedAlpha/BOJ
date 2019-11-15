#include <iostream>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int t = b;
    while (true) {
        if (t % 15 == a % 15 && t % 19 == c % 19) break;
        t += 28;
        if (t > 10000) break;
    }
    printf("%d", t);
}

#include <iostream>

int main() {
    int a, tmp, sum = 0;
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
        scanf("%1d", &tmp);
        sum += tmp;
    }
    printf("%d", sum);
}
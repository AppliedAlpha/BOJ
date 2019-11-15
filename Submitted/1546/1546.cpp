#include <iostream>

int main() {
    int a;
    int n[1000];
    int sum = 0;
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
        scanf("%d", &n[i]);
    }
    int max = n[0];
    for (int i=0; i<a; i++) {
        if (n[i] >= max) max = n[i];
        sum += n[i];
    }
    double ratio = 100.0/max;
    double sum2 = sum * ratio;
    printf("%lf", sum2/a);
    return 0;
}
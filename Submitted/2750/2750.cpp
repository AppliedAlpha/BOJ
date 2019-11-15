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

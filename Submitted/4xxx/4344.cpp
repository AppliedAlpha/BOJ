#include <iostream>
int main() {
    int n, k, st[1003]={0, };
    scanf("%d", &n);
    while (n>0) {
        scanf("%d", &k);
        double avr = 0.0f;
        int tmp = 0;
        for (int i=0; i<k; i++) {
            scanf("%d", &st[i]);
            avr += st[i];
        }
        avr /= k;
        for (int i=0; i<k; i++) {
            if (st[i] > avr) tmp++;
        }
        printf("%.3f%%\n", (double)(tmp*100.0/k));

        for (int i=0; i<k; i++) st[i] = 0;
        n--;
    }
}
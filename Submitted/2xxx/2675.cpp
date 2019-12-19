#include <iostream>
int main() {
    int n, k;
    char str[25] = {0, };
    scanf("%d", &n);
    while (n>0) {
        scanf("%d %s", &k, str);
        for (int i=0; str[i] != NULL; i++) {
            for (int j = 0; j < k; j++) printf("%c", str[i]);
        }
        printf("\n");
        for (int i=0; str[i] != NULL; i++) str[i] = NULL;
        n--;
    }
}
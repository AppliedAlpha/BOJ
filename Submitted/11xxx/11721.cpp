#include <iostream>

int main() {
    char a[101];
    scanf("%s", a);
    for (int i=0; a[i] != NULL; i++) {
        printf("%c", a[i]);
        if (i % 10 == 9) printf("\n");
    }
}
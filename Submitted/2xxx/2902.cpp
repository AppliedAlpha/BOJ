#include <iostream>
int main() {
    char n[103];
    scanf("%s", n);
    for (int i=0; n[i] != NULL; i++) {
        if (n[i] >= 'A' && n[i] <= 'Z') printf("%c", n[i]);
    }
}
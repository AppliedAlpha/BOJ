#include <iostream>
int main() {
    char n[103];
    int t = -1, i;
    scanf("%s", n);
    for (char a='a'; a<='z'; a++) {
        for (i=0; n[i] != NULL; i++) {
            if (n[i] == a) {
                t = i;
                break;
            }
        }
        printf("%d ", t);
        t = -1;
    }
}
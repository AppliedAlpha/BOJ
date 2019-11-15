#include <iostream>

int sugar(int a);

int main() {
    int a;
    scanf("%d", &a);
    printf("%d", sugar(a));
}

int sugar(int a) {
    int sum = a/5;
    a = a%5;
    if (a == 4) {
        if (sum == 0) return -1;
        else return sum + 2;
    }
    else if (a == 3) return sum + 1;
    else if (a == 2) {
        if (sum == 1) return -1;
        else return sum + 2;
    }
    else if (a == 1) return sum + 1;
    else return sum;
}

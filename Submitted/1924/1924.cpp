#include <iostream>

int main() {
    char a[7][5] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y, t = 0;
    scanf("%d %d", &x, &y);
    for (int i=0; i<x; i++) t += m[i];
    printf("%s", a[(t+y)%7]);
}

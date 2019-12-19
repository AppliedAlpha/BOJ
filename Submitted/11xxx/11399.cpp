#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, n[1001]={0, };
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
        scanf("%d", &n[i]);
    }
    sort(n, n+a);
    int sum = 0;
    for (int i=0; i<a; i++) {
        sum += n[i] * (a-i);
    }
    printf("%d", sum);
}

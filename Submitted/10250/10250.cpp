#include <iostream>
using namespace std;
int a, b, v, n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> v;
        printf("%d%02d\n", (v-1) % a + 1, v / a + ((v % a) ? 1 : 0));
    }
}


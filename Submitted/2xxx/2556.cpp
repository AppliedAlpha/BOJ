#include <iostream>
#define range(i, x) int i=0; i<x; i++
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (range(i, n)) {
        for (range(j, n)) cout << '*';
        cout << '\n';
    }
    return 0;
}
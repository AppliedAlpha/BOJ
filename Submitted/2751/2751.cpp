#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main() {
    cin >> n;
    int *a = new int[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<n; i++) cout << a[i] << "\n";
    delete[] a;
}
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main() {
    cin >> n;
    int *a = new int[n]();
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    cout << a[0] << " " << a[n-1];
    delete[] a;
}
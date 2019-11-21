#include <iostream>
#include <algorithm>
using namespace std;

int _find(int tmp, const int* arr, int last, int index) {
    int cnt = 0;
    while (cnt <= 20) {
        if (arr[index] == tmp) return 1;
        else {
            if (index == 1 && index == last-1) return 0;
            if (arr[index] > tmp) index /= 2;
            else if (arr[index] < tmp) index = index * 3 / 2;
        }
        cnt++;
    }
    return 0;
}

int main() {
    int n, m, tmp;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> tmp;
        cout << _find(tmp, arr, n-1, n/2) << '\n';
    }
    delete[] arr;
}
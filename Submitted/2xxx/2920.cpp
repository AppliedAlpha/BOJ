#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 8> a = {1, 2, 3, 4, 5, 6, 7, 8};
    array<int, 8> d = {8, 7, 6, 5, 4, 3, 2, 1};
    array<int, 8> j = {0, };
    for (int i=0; i<8; i++) cin >> j[i];
    if (j == a) cout << "ascending";
    else if (j == d) cout << "descending";
    else cout << "mixed";
}
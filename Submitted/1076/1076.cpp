#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string base[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    string str;
    int j;
    long long c = 0l;
    for (int i=0; i<3; i++) {
        cin >> str;
        for (j=0; j<10; j++) if (base[j] == str) break;
        if (i == 0) c += 10 * j;
        else if (i == 1) c += j;
        else c *= (int) pow(10, j);
    }
    cout << c;
}
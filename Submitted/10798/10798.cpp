#include <iostream>
using namespace std;
char str[5][16];

int main() {
    for (auto & i : str) scanf("%s", &i);
    for (int i=0; i<16; i++) {
        for (int j=0; j<5; j++) {
            if (str[j][i] != NULL) cout << str[j][i];
        }
    }
}
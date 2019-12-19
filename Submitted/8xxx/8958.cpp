#include <iostream>
#include <string>
using namespace std;
int n, t;
string str;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> str;
        int seq = 0;
        t = 0;
        for (int j=0; str[j] != NULL; j++) {
            if (str[j] == 'O') t += ++seq;
            else seq = 0;
        }
        cout << t << "\n";
    }
}
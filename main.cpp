#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    while (str != "ENDOFINPUT") {
        if (str == "START") {
            string str2;
            getline(cin, str2);
            for (int i=0; i<str2.length(); i++) {
                if (str2[i] >= 'A' && str2[i] <= 'Z') {
                    str2[i] = ((str2[i] + 'V' - 'A') - 'A') % 26 + 'A';
                }
            }
            cout << str2 << '\n';
            cin >> str;
        }
        else if (str == "END") cin >> str;
    }
}
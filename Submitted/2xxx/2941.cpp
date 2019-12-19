#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int cnt = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'c' && (s[i + 1] == '-' || s[i + 1] == '=')) {
            cnt++;
            i++;
        }
        else if (s[i] == 'd') {
            if (s[i + 1] == '-') {
                cnt++;
                i++;
            } else if (s[i + 1] == 'z' && s[i + 2] == '=') {
                cnt++;
                i += 2;
            } else cnt++;
        } else if ((s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j') {
            cnt++;
            i++;
        } else if ((s[i] == 's' || s[i] == 'z') && s[i + 1] == '=') {
            cnt++;
            i++;
        }
        else cnt++;
    }
    cout << cnt;
    return 0;
}
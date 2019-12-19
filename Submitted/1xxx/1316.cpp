#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        bool used[26];
        for (bool & i : used) i = false;
        for (int j = 0; j < str.length(); j++) {
            if (used[str[j] - 'a'] && str[j] != str[j - 1]) break;
            else if (!used[str[j] - 'a']) used[str[j] - 'a'] = true;
            if (j == str.length() - 1) cnt++;
        }
    }
    cout << cnt;
}
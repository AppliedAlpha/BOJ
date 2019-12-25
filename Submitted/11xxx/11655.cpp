#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s, '\n');
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i]-'A'+13) % 26 + 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i]-'a'+13) % 26 + 'a';
        }
    }
    cout << s;
}
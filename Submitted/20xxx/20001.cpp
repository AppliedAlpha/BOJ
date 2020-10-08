#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string inp, tmp;
    getline(cin, tmp);
    int cnt = 0;
    getline(cin, inp);
    while (inp != "고무오리 디버깅 끝") {
        if (inp == "문제") cnt++;
        else cnt += (cnt > 0 ? -1 : 2);
        getline(cin, inp);
    }
    cout << (cnt ? "힝구" : "고무오리야 사랑해");
    return 0;
}
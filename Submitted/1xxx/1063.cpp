#include <iostream>
#include <string>
#include <map>
using namespace std;
char k, s; // A~H
int K, S, n; // 1~8
string act;
map<char, int> dx = {{'L', -1}, {'R', 1}};
map<char, int> dy = {{'T', 1}, {'B', -1}};

void action(int t) {
    for (auto i : act) {
        if (i == 'L' || i == 'R') k += dx[i] * t;
        else K += dy[i] * t;
    }
}

void action_s(int t) {
    for (auto i : act) {
        if (i == 'L' || i == 'R') s += dx[i] * t;
        else S += dy[i] * t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> k >> K >> s >> S >> n;
    while (n--) {
        bool press = false;
        cin >> act;
        action(1);
        if (k == s && K == S) {
            action_s(1);
            press = true;
        }
        if (K < 1 || K > 8 || S < 1 || S > 8 || k < 'A' || k > 'H' || s < 'A' || s > 'H') {
            if (press) action_s(-1);
            action(-1);
            continue;
        }

    }
    cout << k << K << '\n' << s << S;
    return 0;
}

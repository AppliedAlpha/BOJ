#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//game[num][0shape,1color,2back]
//0:c 1:s 2:t
//0:r 1:y 2:b
//0:w 1:g 2:b

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int log_count, res = 0;
    vector<vector<int>> game(10, vector<int>(3, 0));
    for (int i=1; i<10; i++) {
        string s, c, b;
        cin >> s >> c >> b;
        if (s[0] == 'C') game[i][0] = 0;
        else if (s[0] == 'S') game[i][0] = 1;
        else game[i][0] = 2;
        if (c[0] == 'R') game[i][1] = 0;
        else if (c[0] == 'Y') game[i][1] = 1;
        else game[i][1] = 2;
        if (b[0] == 'W') game[i][2] = 0;
        else if (b[0] == 'G') game[i][2] = 1;
        else game[i][2] = 2;
    }
    vector<int> index(9, 0);
    vector<int> answers;
    for (int i=0; i<3; i++) index[i] = 1;
    do {
        vector<int> perm;
        int ssum = 0, csum = 0, bsum = 0;
        for (int i=1; i<10; i++) {
            if (index[i-1]) {
                perm.push_back(i);
                ssum += game[i][0];
                csum += game[i][1];
                bsum += game[i][2];
            }
        }
        if (!(ssum%3 || csum%3 || bsum%3)) {
            int answer_tmp = perm[0]*100 + perm[1]*10 + perm[2];
            answers.push_back(answer_tmp);
        }
    } while (prev_permutation(index.begin(), index.end()));
    int answer_count = 0;
    bool called = false;
    cin >> log_count;
    while (log_count--) {
        char type;
        cin >> type;
        if (type == 'H') {
            vector<int> p(3);
            int i;
            cin >> p[0] >> p[1] >> p[2];
            sort(p.begin(), p.end());
            int target = p[0] * 100 + p[1] * 10 + p[2];
            for (i=0; i<answers.size(); i++) {
                if (answers[i] == target) break;
            }
            if (i == answers.size()) res--;
            else {
                answers[i] = 0;
                answer_count++;
                res++;
            }
        }
        else {
            if (!called && answer_count == answers.size()) {
                res += 3;
                called = true;
            }
            else res--;
        }
    }
    cout << res << '\n';
}
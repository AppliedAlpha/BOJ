#include <iostream>
#include <string>
using namespace std;
int border[26] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int rank = 25, star = 0, consecutive = 0;
    string n;
    cin >> n;
    for (auto i : n) {
        if (i == 'W') {
            star++;
            consecutive++;
            if (rank >= 6 && consecutive >= 3) star++;
            if (star > border[rank]) {
                star -= border[rank];
                rank--;
            }
        }
        else {
            consecutive = 0;
            if (rank >= 21 || rank == 0) continue;
            if (rank == 20 && star == 0) continue;
            star--;
            if (star < 0) {
                rank++;
                star += border[rank];
            }
        }
    }
    if (rank >= 1) cout << rank;
    else cout << "Legend";
    return 0;
}
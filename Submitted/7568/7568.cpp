#include <iostream>
using namespace std;
struct state {
    int weigh, tall;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    auto *st = new state[n];
    for (int i=0; i<n; i++) cin >> st[i].weigh >> st[i].tall;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (j == i) continue;
            if (st[j].weigh > st[i].weigh && st[j].tall > st[i].tall)
                cnt++;
        }
        cout << cnt + 1 << " ";
    }
    delete[] st;
}
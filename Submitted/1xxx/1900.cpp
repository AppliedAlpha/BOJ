#include <iostream>
#include <algorithm>

using namespace std;
struct state {
    int power, ring, index;
};

bool stsort(const state &a, const state &b) {
    return a.power + a.ring * b.power > b.power + b.ring * a.power; //a가 b보다 앞일 조건
}

int main() {
    int n;
    cin >> n;
    auto *st = new state[n];
    for (int i = 0; i < n; i++) {
        cin >> st[i].power >> st[i].ring;
        st[i].index = i + 1;
    }
    sort(st, st + n, stsort);
    for (int i = 0; i < n; i++) cout << st[i].index << '\n';
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> in, post;

void order(int inL, int inR, int poL, int poR) {
    if (poL <= poR) {
        int head = post[poR];
        cout << head << ' ';
        int i;
        for (i = inL; in[i] != head; i++);
        int L = i - inL, R = inR - i;
        order(inL, inL + L - 1, poL, poL + L - 1);
        order(inR - R + 1, inR, poR - R, poR - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (auto & i : in) cin >> i;
    for (auto & i : post) cin >> i;
    order(0, n-1, 0, n-1);
    return 0;
}
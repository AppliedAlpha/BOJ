#include <iostream>
#include <algorithm>
using namespace std;
struct state {
    int w, v;
};

bool stsort(const state& a, const state& b) {
    return (a.w != b.w ? a.w < b.w : a.v >= b.v);
}

int main() {
    int n, k;
    state st[101];
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> st[i].w >> st[i].v;
    sort(st, st+n, stsort);
    for (int i=0; i<n; i++) cout << st[i].w << " | " << st[i].v << ", ";
    //12865
}
#include <iostream>
using namespace std;

int main() {
    int ah, am, as, bh, bm, bs, at, bt;
    scanf("%2d:%2d:%2d", &ah, &am, &as);
    scanf("%2d:%2d:%2d", &bh, &bm, &bs);
    at = 3600*ah + 60*am + as;
    bt = 3600*bh + 60*bm + bs;
    int ct = (bt - at + 86400) % 86400;
    printf("%02d:%02d:%02d", ct/3600, (ct/60)%60, ct%60);
}
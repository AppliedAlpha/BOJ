#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, d, tmp, res = 0, cur = 0;
    bool first = true;
    cin >> n >> a >> d;
    while (n--) {
        cin >> tmp;
        if (first && tmp == a) {
            first = false;
            res = 1;
            cur = a;
        }
        if (!first && tmp == cur + d) {
            res++;
            cur += d;
        }
    }
    cout << res;
    return 0;
}

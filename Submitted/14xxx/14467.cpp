#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, cnt = 0;
    cin >> n;
    map<int, int> map;
    while (n--) {
        cin >> a >> b;
        b++;
        if (map[a] == 0) map[a] = b;
        else if (map[a] != b) {
            cnt++;
            map[a] = b;
        }
    }
    cout << cnt;
    return 0;
}
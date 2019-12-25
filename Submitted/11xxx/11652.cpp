#include <iostream>
#include <map>
using namespace std;
typedef map<long long, int> mli;
mli m;
mli::iterator mi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, max_count = 0;
    long long tmp, max_num = 0L;
    cin >> n;
    while (n--) {
        cin >> tmp;
        if (m.count(tmp)) m[tmp]++;
        else m[tmp] = 1;
    }
    for (mi = m.begin(); mi != m.end(); mi++) {
        if (mi->second > max_count) {
            max_num = mi->first;
            max_count = mi->second;
        }
    }
    cout << max_num << '\n';
}
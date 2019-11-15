#include <iostream>
using namespace std;
int k, _max, _index;

int main() {
    cin >> k;
    _max = k;
    _index = 1;
    for (int i=2; i<=9; i++) {
        cin >> k;
        if (k > _max) {
            _max = k;
            _index = i;
        }
    }
    cout << _max << "\n" << _index;
}
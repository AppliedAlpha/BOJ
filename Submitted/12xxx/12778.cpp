#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int cnt;
        char type;
        cin >> cnt >> type;
        if (type == 'C') {
            char *c = new char[cnt];
            for (int j=0; j<cnt; j++) {
                cin >> c[j];
                cout << (int)(c[j]-64) << " ";
            }
            cout << "\n";
            delete[] c;
        }
        else {
            int *c = new int[cnt];
            for (int j=0; j<cnt; j++) {
                cin >> c[j];
                cout << (char)(c[j]+64) << " ";
            }
            cout << "\n";
            delete[] c;
        }
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, t;
vector<int> a;

int main() {
    cin >> n;
    //int *a = new int[n];
    for (int i=0; i<n; i++) {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for (int i=0; i<n; i++) cout << a[i] << "\n";
    //delete[] a;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
signed short t;
vector<signed short> a;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        a.push_back((signed short)t);
    }
    sort(a.begin(), a.end());
    for (int i=0; i<n; i++) cout << a[i] << "\n";
}

#include <iostream>
using namespace std;
int n, t, a[10003] = {0, };

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        a[t]++;
    }
    for (int i=1; i<=10000; i++) {
        if (a[i] != 0) for (int j=0; j<a[i]; j++) cout << a[i] << "\n";
    }
}
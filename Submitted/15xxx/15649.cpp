#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int permutation(vector<int>* v, int r) {
    reverse(v->begin()+r, v->end());
    return next_permutation(v->begin(), v->end());
}


int main() {
    vector<int> v;
    vector<int>::iterator vi;
    int n, r;
    cin >> n >> r;
    for(int i=1; i<=n; i++) v.push_back(i);
    while (true) {
        for(int i=0; i<r; i++) cout << v[i] << ' ';
        cout << '\n';
        if(!permutation(&v, r)) break;
    }
}
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
    int n, r, tmp;
    cin >> n >> r;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    while (true) {
        for(int i=0; i<r; i++) cout << v[i] << ' ';
        cout << '\n';
        if(!permutation(&v, r)) break;
    }
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> _left(26, -1), _right(26, -1);

void preorder(int idx) {
    cout << (char)(idx + 'A');
    if (_left[idx] != -1) preorder(_left[idx]);
    if (_right[idx] != -1) preorder(_right[idx]);
}

void inorder(int idx) {
    if (_left[idx] != -1) inorder(_left[idx]);
    cout << (char)(idx + 'A');
    if (_right[idx] != -1) inorder(_right[idx]);
}

void postorder(int idx) {
    if (_left[idx] != -1) postorder(_left[idx]);
    if (_right[idx] != -1) postorder(_right[idx]);
    cout << (char)(idx + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char x, y, z;
    while (n--) {
        cin >> x >> y >> z;
        _left[x-'A'] = (y != '.' ? y-'A' : -1);
        _right[x-'A'] = (z != '.' ? z-'A' : -1);
    }
    // Root Node = A;
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll counter = 0LL;
int n, a, tmp;
map<int, int> depth;

// ~= 2957

/*
class BST {
    struct Node {
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root;

    Node* insert(int x, Node* node) {
        if (node == nullptr) { // if node is empty
            node = new Node;
            node -> data = x;
            node -> left = node -> right = nullptr;
            //depth[x] = 0;
            return node;
        }
        //else if (x < node -> data) node -> left = insert(x, node -> left);
        //else if (x > node -> data) node -> right = insert(x, node -> right);
        counter++;
        if (x < node -> data) {
            if (node -> left == nullptr) {
                node -> left = new Node;
                node -> left -> data = x;
            }
            else insert(x, node -> left);
        }
        else if (x > node -> data) {
            if (node -> right == nullptr) {
                node -> right = new Node;
                node -> right -> data = x;
            }
            else insert(x, node -> right);
        }
        return node;
    }

public:
    BST() { root = nullptr; }
    void insert(int x) { root = insert(x, root); }
};
*/

// 그 노드의 깊이만큼 insert 함수에서 counter가 오르는 성질 이용
// n개의 쿼리마다 실행 시간 log n => O(n log n)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //BST bst;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        //bst.insert(a);
        if (!i) {
            depth[a] = 0;
        }
        else {
            auto it = depth.upper_bound(a);
            tmp = 0;
            if (it != depth.end()) tmp = it -> second;
            if (it != depth.begin()) {
                it--;
                tmp = max(tmp, it -> second);
            }
            depth[a] = tmp + 1;
            counter += depth[a];
        }
    }
    cout << counter + n;
    return 0;
}

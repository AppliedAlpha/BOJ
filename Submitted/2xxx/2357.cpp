#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 2147483646
#define MIN -1
using namespace std;
int n, q, a, b, temp;
int minseg[400004], maxseg[400004], arr[100001];

// ~= 14428
//Segment Tree
int update_min(int i, int x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return minseg[nidx];
    if (node_st == node_en) return minseg[nidx] = x;
    int mid = (node_st + node_en) / 2;
    return minseg[nidx] = min(update_min(i, x, 2*nidx, node_st, mid), update_min(i, x, 2*nidx+1, mid+1, node_en));
}

int update_max(int i, int x, int nidx, int node_st, int node_en) {
    if (i < node_st || i > node_en) return maxseg[nidx];
    if (node_st == node_en) return maxseg[nidx] = x;
    int mid = (node_st + node_en) / 2;
    return maxseg[nidx] = max(update_max(i, x, 2*nidx, node_st, mid), update_max(i, x, 2*nidx+1, mid+1, node_en));
}

int query_min(int i, int j, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return MAX;
    if (i <= node_st && j >= node_en) return minseg[nidx];
    int mid = (node_st + node_en) / 2;
    return min(query_min(i, j, 2*nidx, node_st, mid), query_min(i, j, 2*nidx+1, mid+1, node_en));
}

int query_max(int i, int j, int nidx, int node_st, int node_en) {
    if (j < node_st || i > node_en) return MIN;
    if (i <= node_st && j >= node_en) return maxseg[nidx];
    int mid = (node_st + node_en) / 2;
    return max(query_max(i, j, 2*nidx, node_st, mid), query_max(i, j, 2*nidx+1, mid+1, node_en));
}

int update(int i, int x) {
    update_min(i, x, 1, 1, n);
    update_max(i, x, 1, 1, n);
    return 0;
}

int query(int i, int j, int t) {
    return (t == MIN ? query_min(i, j, 1, 1, n) : query_max(i, j, 1, 1, n));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    memset(minseg, MAX, sizeof(minseg));
    memset(maxseg, MIN, sizeof(maxseg));
    for (int i=1; i<=n; i++) {
        cin >> temp;
        arr[i] = temp;
        update(i, temp);
    }
    while (q--) {
        cin >> a >> b;
        cout << query(a, b, MIN) << ' ' << query(a, b, MAX) << '\n';
    }
    return 0;
}
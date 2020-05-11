#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <list>
#include <map>
using namespace std;

struct node {
    vector<int> values;
    int numberOfItems;
    bool flag;
};

typedef list<node>::iterator lni;
typedef list<node>::const_iterator lnci;

int GrayEncode[16] = {0, 1, 3, 2, 4, 5, 7, 6, 12, 13, 15, 14, 8, 9, 11, 10};
pair<int, int> Decode[16] = {
        {0, 0}, {1, 0}, {3, 0}, {2, 0},
        {0, 1}, {1, 1}, {3, 1}, {2, 1},
        {0, 3}, {1, 3}, {3, 3}, {2, 3},
        {0, 2}, {1, 2}, {3, 2}, {2, 2},
};

map<pair<int, int>, int> kmap, kmapValues, temp;
list<node> blocks;
int n, m;

vector<int> GetMapBoolValue(int x, int y) {
    vector<int> b;
    int i = kmapValues[{x, y}];
    while (i > 0) {
        b.insert(b.begin(), i % 2);
        i /= 2;
    }
    for (int j=b.size(); j<4; j++) b.insert(b.begin(), 0);
    return b;
}

int IsJoinable(vector<int> &a, vector<int> &b) {
    int c = 0, x;
    for(int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) {
            c++;
            x = i;
        }
    }
    return (c == 1 ? x + 1 : 0);
}

bool IsAtCell(int x, int y, vector<int> &a) {
    vector<int> b = GetMapBoolValue(x, y);
    for (int i=0; i<a.size(); i++)
        if ((a[i] != b[i]) && (a[i] != 2)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialization
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            kmap[{j, i}] = 0;
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            kmapValues[{j, i}] = GrayEncode[j + (i * 4)];
        }
    }

    // Input
    cin >> n;
    while (n--) {
        cin >> m;
        kmap[{Decode[m].first, Decode[m].second}] = 1;
    }

    /* Test Line
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) cout << kmap[{j, i}] << ' ';
        cout << '\n';
    }
    */

    // 1. Put blocks in the list
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (kmap[{j, i}] == 1) {
                node ne;
                ne.numberOfItems = 1;
                ne.flag = 0;
                ne.values = GetMapBoolValue(j, i);
                blocks.push_back(ne);
            }
        }
    }

    // 2. Merge
    for (int i=1; i<=4; i++) {
        for (lni a=blocks.begin(); a != blocks.end(); a++) {
            for(lni b=blocks.begin(); b != blocks.end(); b++) {
                if((a->numberOfItems == (int)pow(2, i-1)) &&
                   (b->numberOfItems == (int)pow(2, i-1))) {
                    int x = IsJoinable(a->values, b->values);
                    if (x > 0) { // Joinable
                        node ne;
                        ne.numberOfItems = a->numberOfItems * 2;
                        ne.flag = 0;
                        for (int j=0; j < a->values.size(); j++) {
                            if (j != (x - 1))
                                ne.values.insert(ne.values.end(), a->values[j]);
                            else
                                ne.values.insert(ne.values.end(), 2);
                        }

                        a->flag = 1;
                        b->flag = 1;

                        bool exist = false;
                        for (lnci c=blocks.begin(); c != blocks.end(); c++) {
                            if (ne.values == c->values) {
                                exist = true;
                                break;
                            }
                        }
                        if (!exist) blocks.push_back(ne);
                    }
                }
            }
        }
    }

    // 3. Deleting Duplicates
    for (lni a=blocks.begin(); a != blocks.end();) {
        if (a->flag == 1) a = blocks.erase(a);
        else a++;
    }

    // 4. Clearing Unneeded Nodes
    for (lni a=blocks.begin(); a != blocks.end(); a++) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                temp[{j, i}] = 0;
            }
        }

        for (lni b=blocks.begin(); b != blocks.end(); b++) {
            if (a != b) {
                for (int i=0; i<4; i++) {
                    for (int j=0; j<4; j++) {
                        if (IsAtCell(j, i, b->values)) temp[{j, i}] = 1;
                    }
                }
            }
        }

        bool del = true;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (temp[{j, i}] != kmap[{j, i}]) {
                    del = false;
                    break;
                }
            }
            if (!del) break;
        }
        if (del) a = blocks.erase(a);
    }

    // 5. Result
    cout << blocks.size() << '\n';
    return 0;
}
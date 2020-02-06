#include "bogoSort.h"
#include <algorithm>
#include <vector>
using namespace std;

void sort_array(int N) {
    vector<int> arr = copy_array();
    vector<int> comp = arr;
    sort(comp.begin(), comp.end());
    int st = 0, ed = N - 1;
    while (!equal(arr.begin(), arr.end(), comp.begin())) {
        while (arr[st] != st) {
            for (int i=st; i<N; i++) {
                if (arr[i] == st) {
                    ed = i;
                    break;
                }
            }
            shuffle_array(st, ed);
            arr = copy_array();
        }
        st++;
    }
}
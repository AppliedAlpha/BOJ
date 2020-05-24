#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define i32_max 2147483646
#define mod 1000000007
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;

class Vertex {
public:
    int index, dist, post = 0;

    Vertex(int index, int dist, int post): index(index), dist(dist), post(post) {

    }
    Vertex(int index): index(index) {
        dist = i32_max;
    }

    void setDist(int d) {
        dist = (d < 0 ? i32_max : d);
    }

    bool operator >(const Vertex &v) const {
        return dist > v.dist;
    }

    bool operator <(const Vertex &v) const {
        return dist < v.dist;
    }
};

class Graph {
public:
    int _n = 0;
    vector<Vertex> vx;
    vector<vector<pii>> adj;
    priority_queue<Vertex> pq;

};

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    while (m--) {

    }
    return 0;
}
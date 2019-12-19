#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct state {
    int x, y, price;
};
bool visited[101][101];
int field[101][101];
vector<state> adj[101][101];

int bfs(int d, int r) {
    queue<state> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.x == d-1 && s.y == r-1) return s.price;
        if (s.x < d-1 && field[s.x+1][s.y])
            adj[s.x][s.y].push_back({s.x+1, s.y, s.price+1});
        if (s.y < r-1 && field[s.x][s.y+1])
            adj[s.x][s.y].push_back({s.x, s.y+1, s.price+1});
        if (s.x > 0 && field[s.x-1][s.y])
            adj[s.x][s.y].push_back({s.x-1, s.y, s.price+1});
        if (s.y > 0 && field[s.x][s.y-1])
            adj[s.x][s.y].push_back({s.x, s.y-1, s.price+1});
        for (auto u : adj[s.x][s.y]) {
            if (visited[u.x][u.y]) continue;
            if (u.x == d-1 && u.y == r-1) return u.price;
            visited[u.x][u.y] = true;
            q.push(state{u.x, u.y, u.price});
        }
    }
    return -1;
}

int main() {
    int d, r;
    cin >> d >> r;
    for (int i=0; i<d; i++) {
        for (int j=0; j<r; j++) {
            scanf("%1d", &field[i][j]);
            visited[i][j] = false;
        }
    }
    cout << bfs(d, r);
}
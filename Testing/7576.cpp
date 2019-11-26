#include <iostream>
#include <queue>
#include <vector>
using namespace std;
short field[1001][1001]; //y and x (field[n][m])
bool visited[1001][1001]; //y and x
int cnt, m, n;
struct state {
    int y, x;
};

void bfs(int y, int x) { //??
    vector<state> adj[50][50];
    queue<state> q;
    visited[y][x] = true;
    q.push({y, x});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.y > 0 && field[s.y-1][s.x]) adj[s.y][s.x].push_back(state{s.y-1, s.x});
        if (s.x > 0 && field[s.y][s.x-1]) adj[s.y][s.x].push_back(state{s.y, s.x-1});
        if (s.y < n-1 && field[s.y+1][s.x]) adj[s.y][s.x].push_back(state{s.y+1, s.x});
        if (s.x < m-1 && field[s.y][s.x+1]) adj[s.y][s.x].push_back(state{s.y, s.x+1});
        for (auto u : adj[s.y][s.x]) {
            if (visited[u.y][u.x]) continue;
            visited[u.y][u.x] = true;
            q.push({u.y, u.x});
        }
    }
    cnt++;
}

void init_visited() {
    for (auto & i : visited) for (bool & j : i) j = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    cnt = 0;
    init_visited();
    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
            cin >> field[i][j];
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            if (!visited[a][b] && field[a][b]) bfs(a, b); //y and x
    cout << cnt << '\n';
}
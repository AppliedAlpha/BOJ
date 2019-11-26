#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool field[50][50]; //y and x (field[n][m])
bool visited[50][50]; //y and x
int cnt, m, n;
struct state {
    int y, x;
};

void bfs(int y, int x) {
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

void init() {
    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            field[j][i] = false;
            visited[j][i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, k, tx, ty;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        cnt = 0;
        init();
        for (int j = 0; j < k; j++) {
            cin >> tx >> ty;
            field[ty][tx] = true;
        }
        for (int a = 0; a < n; a++)
            for (int b = 0; b < m; b++)
                if (!visited[a][b] && field[a][b]) bfs(a, b); //y and x
        cout << cnt << '\n';
    }
}
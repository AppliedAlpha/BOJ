#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, cnt;
char field[102][102];
bool visited[102][102];

struct state {
    int y, x;
};

void init_visited() {
    for (auto & i : visited) for (bool & j : i)
            j = false;
}

void rg_clear() {
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
            if (field[i][j] == 'G') field[i][j] = 'R';
}

void bfs(int y, int x) {
    char basic = field[y][x];
    vector<state> adj[102][102];
    queue<state> q;
    visited[y][x] = true;
    q.push({y, x});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.y > 0 && field[s.y - 1][s.x] == basic)
            adj[s.y][s.x].push_back({s.y - 1, s.x});
        if (s.x > 0 && field[s.y][s.x - 1] == basic)
            adj[s.y][s.x].push_back({s.y, s.x - 1});
        if (s.y < n - 1 && field[s.y + 1][s.x] == basic)
            adj[s.y][s.x].push_back({s.y + 1, s.x});
        if (s.x < n - 1 && field[s.y][s.x + 1] == basic)
            adj[s.y][s.x].push_back({s.y, s.x + 1});
        for (auto u : adj[s.y][s.x]) {
            if (visited[u.y][u.x]) continue;
            visited[u.y][u.x] = true;
            q.push({u.y, u.x});
        }
    }
    cnt++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> field[i][j];
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) bfs(i, j);
    cout << cnt << ' ';
    init_visited();
    rg_clear();
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) bfs(i, j);
    cout << cnt;
}
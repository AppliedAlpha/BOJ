#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, l, w, t, t1, t2, cnt = 0;
bool visited[51][51];
char field[51][51];
struct state {
    int i, j;
};

void init() {
    for (auto & i : visited) for (bool & j : i) j = false;
    for (auto & i : field) for (char & j : i) j = '0';
}

void bfs(int i, int j) {
    vector<state> adj[51][51];
    queue<state> q;
    visited[i][j] = true;
    q.push(state{i, j});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.i > 0 && field[s.i-1][s.j] == '1') adj[s.i][s.j].push_back(state{s.i-1, s.j});
        if (s.j > 0 && field[s.i][s.j-1] == '1') adj[s.i][s.j].push_back(state{s.i, s.j-1});
        if (s.i < w-1 && field[s.i+1][s.j] == '1') adj[s.i][s.j].push_back(state{s.i+1, s.j});
        if (s.j < l-1 && field[s.i][s.j+1] == '1') adj[s.i][s.j].push_back(state{s.i, s.j+1});
        for (auto u : adj[s.i][s.j]) {
            if (visited[u.i][u.j]) continue;
            visited[u.i][u.j] = true;
            q.push(state{u.i, u.j});
        }
    }
    cnt++;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        init();
        cnt = l = w = 0;
        cin >> l >> w >> t;
        for (int j=0; j<t; j++) {
            cin >> t1 >> t2;
            field[t1][t2] = '1';
        }
        for (int k=0; k<w; k++) {
            for (int j=0; j<l; j++) {
                if (field[k][j] == '1' && !visited[k][j]) bfs(k, j);
            }
        }
        cout << cnt << "\n";
        /*
         for (int k=0; k<w; k++) {
            for (int j=0; j<l; j++) {
                cout << (visited[k][j] ? '*' : '.');
            }
            cout << "\n";
        }
         */
    }
}
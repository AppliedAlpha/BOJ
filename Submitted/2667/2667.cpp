#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
bool visited[26][26];
char field[26][26];
struct state {
    int i, j;
};
vector<state> adj[26][26];
vector<int> cnt;

void initVisited() {
    for (auto & i : visited)
        for (bool & j : i) j = false;
}

void bfs(int i, int j) {
    int c = 0;
    queue<state> q;
    visited[i][j] = true;
    //cout << i << " ";
    c++;
    q.push(state{i, j});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.i > 0 && field[s.i-1][s.j] == '1') adj[s.i][s.j].push_back(state{s.i-1, s.j});
        if (s.j > 0 && field[s.i][s.j-1] == '1') adj[s.i][s.j].push_back(state{s.i, s.j-1});
        if (s.i < n-1 && field[s.i+1][s.j] == '1') adj[s.i][s.j].push_back(state{s.i+1, s.j});
        if (s.j < n-1 && field[s.i][s.j+1] == '1') adj[s.i][s.j].push_back(state{s.i, s.j+1});
        for (auto u : adj[s.i][s.j]) {
            if (visited[u.i][u.j]) continue;
            visited[u.i][u.j] = true;
            //cout << u << " ";
            c++;
            q.push(state{u.i, u.j});
        }
    }
    cnt.push_back(c);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> field[i][j];
        }
    }
    initVisited();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (field[i][j] == '1' && !visited[i][j]) bfs(i, j);
        }
    }
    cout << cnt.size() << "\n";
    sort(cnt.begin(), cnt.end()); // #include <algorithm>
    for (int i : cnt) cout << i << "\n";
}
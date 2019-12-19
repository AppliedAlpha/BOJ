#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v, t1, t2;
bool visited[1001];
vector<int> adj[1001];

void initVisited() {
    for (bool & i : visited) i = false;
}

void dfs(int i) { //Depth-First Search
    if (visited[i]) return; //방문했을 시 탈주
    visited[i] = true; //방문 체크
    cout << i << " ";
    for (auto u : adj[i]) dfs(u); //재귀 호출로 방문
}

void bfs(int i) { //Breadth-First Search
    queue<int> q;
    visited[i] = true; //방문 체크
    cout << i << " ";
    q.push(i); //큐에 삽입
    while (!q.empty()) { //큐가 끝날 때까지
        int s = q.front(); q.pop(); //맨 앞을 빼내서
        for (auto u : adj[s]) { //큐의 정점에서 간선 확인
            if (visited[u]) continue; //방문했으면 돌아감
            visited[u] = true; //아닐 시 방문
            cout << u << " ";
            q.push(u); //큐에 뒤 순서로 밀어줌
        } //한 정점에서 다 빼내면 큐에서 다음 정점부터 탐색
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    for (int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());
    initVisited();
    dfs(v);
    initVisited();
    cout << "\n";
    bfs(v);
}
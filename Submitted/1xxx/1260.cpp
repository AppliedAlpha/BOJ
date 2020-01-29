//20200125
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void init_visited() {
    for (auto && i : visited) i = false;
}

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    cout << v << ' ';
    for (auto i : adj[v]) dfs(i);
}

void bfs(int v) {
    queue<int> queue;
    visited[v] = true;
    cout << v << ' ';
    queue.push(v);
    while (!queue.empty()) {
        int index = queue.front();
        queue.pop();
        for (auto i : adj[index]) {
            if (visited[i]) continue;
            visited[i] = true;
            cout << i << ' ';
            queue.push(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, v, a, b;
    cin >> n >> m >> v;
    adj.resize(n+1);
    visited.resize(n+1);
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto & i : adj) sort(i.begin(), i.end());
    dfs(v);
    cout << '\n';
    init_visited();
    bfs(v);
    return 0;
}



//20191118
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
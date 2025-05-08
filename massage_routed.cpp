#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int parent[N];

void bfs(int start, int end) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                if (v == end) return; // early stop if reached destination
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1, n);

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int v : path) cout << v << " ";
        cout << endl;
    }

    return 0;
}

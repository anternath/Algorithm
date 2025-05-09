#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> ar[N];
bool vis[N];
int last_node;

void dfs(int node) {
    vis[node] = true;
    last_node = node; // update last visited node in component
    for (int child : ar[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    vector<int> reps;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            reps.push_back(last_node); // last node from this component
        }
    }

    cout << reps.size() - 1 << "\n";
    for (int i = 0; i + 1 < reps.size(); i++) {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, s;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back({y - 1, w});
        adj[y - 1].push_back({x - 1, w});
    }
    cin >> s;
    s--;
    vector<int> dist(n, 1000000000);
    dist[s] = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        vis[u] = true;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != s) {
            cout << dist[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}
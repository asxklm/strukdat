#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define Size 100010

vector<lli> adj[Size];
bool vis[Size];
lli a, b, total = 0;
lli cc[Size];

void dfs(lli s, lli sum)
{
    if (vis[s])
        return;

    vis[s] = 1;

    if (cc[s])
        sum++;
    else
        sum = 0;

    if (sum > b)
        return;

    if (s != 1 && adj[s].size() == 1)
    {
        total++;
    }

    for (int i = 0; i < adj[s].size(); i++)
    {
        dfs(adj[s][i], sum);
    }
}

int main()
{
    lli i;
    lli x, y;

    memset(vis, 0, sizeof(vis));

    cin >> a >> b;

    for (i = 1; i <= a; i++)
        cin >> cc[i];

    for (i = 0; i < a - 1; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cout << total;

    return 0;
}
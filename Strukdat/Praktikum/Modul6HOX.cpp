#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a, b, c[100000], answer;
vector<int> v[100000];
bool vis[100000];

int main()
{
    cin >> a >> b;
    for(int i = 0; i < a; i++) cin >> c[i];
    for(int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < a; i++)
    {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int ab = 1e9;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            ab = min(ab, c[now]);
            for(int x : v[now])
            {
                if(vis[x]) continue;
                q.push(x);
                vis[x] = true;
            }
        }
        answer += ab;
    }
    cout << answer << endl;
    return 0;
}
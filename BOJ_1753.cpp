#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int v,e,st;
vector<pii> adj[20005];
const int INF = 1e9+10;

int d[20005];

void solve()
{
    cin >> v >> e >> st;
    fill(d,d+v+1,INF);
    while(e--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    priority_queue<pii,vector<pii>,greater<pii>> que; // 거리 정점

    d[st] = 0;
    que.push({d[st],st});

    while(!que.empty())
    {
        auto cur = que.top();
        que.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second])
        {
            if(d[nxt.second] <= d[cur.second] + nxt.first)continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            que.push({d[nxt.second],nxt.second});
        }
    }

    for(int i = 1;i<=v;i++)
    {
        if(d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }

} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
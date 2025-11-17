#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n,m,x;
vector<pii> adj[1005];// 가중치, 경로
int dist[1005];
int dist_x[1005];


int dijkstra(int st)
{
    int const INF = INT_MAX;
    fill(dist,dist+n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>> que;
    dist[st] = 0;
    que.push({dist[st],st});
    while(!que.empty())
    {
        auto cur = que.top();que.pop();
        if(dist[cur.second] != cur.first) continue;
        
        for(auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            que.push({dist[nxt.second],nxt.second});
        }
    }
    if(st == x)
    {
        for(int i = 1; i<=n;i++)dist_x[i] =dist[i];
    }
    return dist[x];
}
void solve()
{   
    cin >> n >> m >> x;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    dijkstra(x);
    for(int i = 1;i<=n;i++)
    {
        if(i != x)
        {
            dist_x[i] += dijkstra(i);
        }
    }
    cout << *max_element(dist_x+1,dist_x+n+1);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
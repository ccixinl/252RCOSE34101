#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n,m,a,b;
vector<pii> adj[1005]; // adj[x] = {cost,y};
int dist[1005];

void bfs()
{
    priority_queue<pii,vector<pii>,greater<>> que;
    que.push({0,a}); 
    dist[a] = 0;
    while(!que.empty())
    {
        auto cost = que.top().first;
        auto cur = que.top().second;
        que.pop();

        if(dist[cur] < cost) continue;

        for(auto nxt : adj[cur])
        {
            int newcost = cost + nxt.first;
            if(newcost < dist[nxt.second])
            {
                dist[nxt.second] = newcost;
                que.push({newcost,nxt.second});
            }

        }
    }
}
void solve()
{
    cin >> n >> m;
    while(m--)
    {
        int x,y,cost;
        cin >> x >> y >> cost;
        adj[x].push_back({cost,y});
    }    
    fill(dist,dist+n+1,1e9);
    cin >> a >> b;
    bfs();
    cout << dist[b];

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
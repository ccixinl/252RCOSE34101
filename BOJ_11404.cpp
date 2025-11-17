#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n,m;
int dp[105][105];
const int INF = 0x3f3f3f3f;
void solve()
{
    cin >> n >> m;
    for(int i = 1;i<= n;i++)fill(dp[i],dp[i]+1+n,INF);

    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v],w);
    }
    
    for(int i = 1;i<=n;i++)
    {
        dp[i][i] = 0; 
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                dp[j][k] = min(dp[j][k],dp[j][i] + dp[i][k]);
            }
        }
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(dp[i][j] == INF) cout << 0 <<' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
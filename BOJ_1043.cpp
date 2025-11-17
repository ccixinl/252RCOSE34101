#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n,m;
bool check[55];
vector<int> party[55];
vector<int> person_party[55];

void solve()
{
    cin >> n >> m;
    int t_num;
    cin >> t_num;

    queue<int> que;
    for(int i = 0;i<t_num;i++)
    {
        int a;
        cin >> a;
        check[a] = true;
        que.push(a);
    }
    for(int i = 0;i<m;i++)
    {
        int a;
        cin >> a;
        for(int j = 0; j< a ;j++)
        {
            int num;
            cin >> num;
            party[i].push_back(num);
            person_party[num].push_back(i);
        }
    }

    bool vis[55];
    fill(vis,vis+m+1,false);

    while(!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for(auto pa : person_party[cur])
        {
            if(vis[pa]) continue;
            for(auto people : party[pa])
            {
                if(!check[people])
                {
                    check[people] = 1;
                    que.push(people);
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < m;i++)
    {
        bool able = true;
        for(auto p : party[i])
        {
            if(check[p])
            {
                able = false;
                break;
            }
        }
        if(able)ans++;
    }
    
    cout << ans;
} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
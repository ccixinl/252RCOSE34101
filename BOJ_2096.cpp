#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
int arr[3];
int dp1[2][3],dp2[2][3];

void solve()
{  
    cin >> n;
    for(int i = 0;i<3;i++)
    {
        cin >> arr[i];
        dp1[0][i] = dp2[0][i] = arr[i]; 
    }

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<3;j++)  cin >> arr[j];
            
        dp1[1][0] = max(dp1[0][0],dp1[0][1]) + arr[0];
        dp1[1][1] = max({dp1[0][0],dp1[0][1],dp1[0][2]}) + arr[1];
        dp1[1][2] = max(dp1[0][1],dp1[0][2]) + arr[2];
        
        dp2[1][0] = min(dp2[0][0],dp2[0][1]) + arr[0];
        dp2[1][1] = min({dp2[0][0],dp2[0][1],dp2[0][2]}) + arr[1];
        dp2[1][2] = min(dp2[0][1],dp2[0][2]) + arr[2];

        for(int j = 0;j<3;j++)
        {
            dp1[0][j] = dp1[1][j];
            dp2[0][j] = dp2[1][j];
        }
    }
    int max_e = max({dp1[0][1],dp1[0][2],dp1[0][0]});
    int min_e = min({dp2[0][1],dp2[0][2],dp2[0][0]});

    cout << max_e <<'\n' << min_e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
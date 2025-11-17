#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int n,m;
int arr[600][600];
void solve()
{  
    cin >> n >> m;
    for(int i = 3;i < 3 + n;i++)
    {
        for(int j = 3;j < 3 + m;j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 3;i< 3 + n;i++)
    {
        for(int j = 3;j< 3 + m;j++)
        {
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3])); // --
            ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j])); // |
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1])); //ㅁ
            ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1])); // L
            ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j+2])); // |^-
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1])); // ㄱ
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i-1][j+2]));//__|
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i-2][j+1]));
            ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]));
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j]));
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2]));
            ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1]));
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i-1][j+2]));
            ans = max(ans,(arr[i][j]+arr[i-1][j]+arr[i-1][j+1]+arr[i-2][j+1]));
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2]));
            ans = max(ans,(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]));
			ans = max(ans,(arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1]));
			ans = max(ans,(arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]));
			ans = max(ans,(arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1]+arr[i+1][j]));

        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj[1005][1005];
int dist[1005][1005][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            adj[i][j] = s[j] - '0';
        }
    }

    memset(dist, -1, sizeof(dist));
    queue<pair<pair<int, int>, bool>> que;
    que.push({{0, 0}, false});
    dist[0][0][0] = 1;

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        int x = cur.first.first, y = cur.first.second;
        bool broke = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 벽을 만나고 아직 안 부순 경우
            if (adj[nx][ny] == 1 && !broke && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                que.push({{nx, ny}, true});
            }
            // 벽이 아니고 방문한 적 없는 경우
            else if (adj[nx][ny] == 0 && dist[nx][ny][broke] == -1) {
                dist[nx][ny][broke] = dist[x][y][broke] + 1;
                que.push({{nx, ny}, broke});
            }
        }
    }

    int res1 = dist[n-1][m-1][0];
    int res2 = dist[n-1][m-1][1];

    if (res1 == -1 && res2 == -1)
        cout << -1;
    else if (res1 == -1)
        cout << res2;
    else if (res2 == -1)
        cout << res1;
    else
        cout << min(res1, res2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}

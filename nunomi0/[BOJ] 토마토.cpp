#include <iostream>
#include <queue>
using namespace std;

int n,m,arr[1010][1010],zero_cnt=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==0) zero_cnt++;
        }
    }

    if (zero_cnt==0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]==1) {
                pq.push({0,{i,j}});
            }
        }
    }

    while (!pq.empty()) {
        int cnt=pq.top().first;
        int cx=pq.top().second.first;
        int cy=pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m && arr[nx][ny]==0) {
                pq.push({cnt+1,{nx,ny}});
                arr[nx][ny]=1;
                zero_cnt--;
                if (zero_cnt==0) {
                    cout << cnt+1;
                    return 0;
                }
            }
        }
    }

    cout << -1;
}

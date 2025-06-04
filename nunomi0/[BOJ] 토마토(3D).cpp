#include <iostream>
#include <queue>
using namespace std;

struct point {
    int day,z,y,x;
};

queue<point> q;
int m,n,h,arr[110][110][110],visited[110][110][110],ans=0;
int dx[6]={0,0,0,0,1,-1}; // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dy[6]={0,0,-1,1,0,0};
int dz[6]={-1,1,0,0,0,0};


int main() {
    cin >> m >> n >> h;
    for (int i = 0; i<h; i++) {
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<m; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k]==1) {
                    q.push(point{1,i,j,k});
                    visited[i][j][k]=1;
                }
            }
        }
    }

    while (!q.empty()) {
        point p = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nd=p.day+1;
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            int nz=p.z+dz[i];
            if (0<=nx && nx<m && 0<=ny && ny<n && 0<=nz && nz<h) {
                if (arr[nz][ny][nx]==0 && !visited[nz][ny][nx]) {
                    arr[nz][ny][nx]=1;
                    visited[nz][ny][nx]=nd;
                    q.push(point{nd,nz,ny,nx});
                }
            }
        }
    }

    for (int i = 0; i<h; i++) {
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<m; k++) {
                if (arr[i][j][k]==0) {
                    cout << -1;
                    return 0;
                }
                ans=max(ans,visited[i][j][k]);
            }
        }
    }
    cout << ans-1;
}

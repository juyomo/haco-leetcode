#include <iostream>
using namespace std;

// 방문할 수 있는 최대 칸의 개수

int n,m;

int main() {
    cin >> n >> m;
    if (n==1) cout << 1;
    else if (n==2) cout << min(4,(m-1)/2+1);
    else if (m<7) cout << min(4,m);
    else cout << m-2;
}

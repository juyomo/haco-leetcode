#include <iostream>
#include <queue>
using namespace std;

int n, m, ans=0;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        pq.push(m);
    }
    while (pq.size()>1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int tmp = a + b;
        ans += tmp;
        pq.push(tmp);
    }
    cout << ans;
}

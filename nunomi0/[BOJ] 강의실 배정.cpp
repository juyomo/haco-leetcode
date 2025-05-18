#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 가장 먼저 끝나는 수업 기준으로 정렬
// 공강이 없는게 베스트
// 겹치고 depth 계산은 시간 초과
// 아무래도 pq를 쓰는게 맞는 것 같은데

int n,s,t;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> s >> t;
        v.push_back({s,t});
    }
    sort(v.begin(), v.end());

    pq.push(0);
    for (int i = 0; i<n; i++) {
        if (pq.top()<=v[i].first) pq.pop();
        pq.push(v[i].second);
    }

    cout << pq.size();
}

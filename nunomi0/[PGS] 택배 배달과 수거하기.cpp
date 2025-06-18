#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    
    // 이번에 갈 거리 = max(deleveries 가장 먼 것, pickups 가장 먼 것);
    // 갈 때 deleveries, 올 때 pickups
    
    queue<pair<int,int>> q[2];

    for (int i = n-1; i>=0; i--){
        if (deliveries[i]) q[0].push({i+1,deliveries[i]});
        if (pickups[i]) q[1].push({i+1,pickups[i]});
    }
    
    long long ans=0;
    int cnt;
    while (true){
        if (q[0].empty() && q[1].empty()) break;
        else if (q[0].empty()) ans+=2*(q[1].front().first);
        else if (q[1].empty()) ans+=2*(q[0].front().first);
        else ans+=2*max(q[0].front().first,q[1].front().first);
        
        for (int i = 0; i<2; i++){
            cnt=0;
            while (!q[i].empty()){
                cnt++;
                q[i].front().second--;
                if (q[i].front().second==0) q[i].pop();
                if (cnt>=cap) break;
            }
        }
    }
    
    return ans;
}

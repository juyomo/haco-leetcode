#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    
    map<int,int> m;
    
    for (int i = 0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    
    vector<pair<int,int>> v; // { value, key }
    for (auto iter=m.begin(); iter!=m.end(); iter++){
        v.push_back({iter->second, iter->first});
    }
    
    sort(v.rbegin(), v.rend());
    
    int cnt = 0;
    int ans = 0;
    for (int i = 0 ; i<v.size(); i++){
        ans++;
        cnt+=v[i].first;
        if (cnt>=k) break;
    }
    
    return ans;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    
    stack<int> s;
    int cur = 1;
    int ans = 0;
    
    for (int i = 0; i<order.size(); i++){
        int check=0;
        if (!s.empty() && s.top()==order[i]){
            s.pop();
            check=1;
        }
        else {
            while (cur<=order.size()){
                if (cur==order[i]){
                    check=1;
                    cur++;
                    break;
                }
                else {
                    s.push(cur++);
                }
            }
        }
        if (check) ans++;
        else break;
    }
    
    return ans;
}

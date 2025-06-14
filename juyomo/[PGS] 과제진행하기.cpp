// Author: Juyoung Moon
// Solved on Sat, June 14, 2025
// https://school.programmers.co.kr/learn/courses/30/lessons/176962

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<string, int> SubAndDur;

bool compare(const vector<string>& a, const vector<string>& b) {
    return a[1] < b[1];
}

int toTime(string t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), compare);
    
    vector<string> answer;
    stack<SubAndDur> remaining;
    
    for (int i = 0; i < plans.size() - 1; i++) {
        const vector<string>& hw = plans[i];
        int currTime = toTime(hw[1]);
        int nextStart = toTime(plans[i+1][1]);
        
        remaining.push(make_pair(hw[0], stoi(hw[2])));
        
        while (remaining.size() > 0 && currTime < nextStart) {
            string currSub = remaining.top().first;
            int currDur = remaining.top().second;
            remaining.pop();
            currTime += currDur;
            
            if (currTime <= nextStart) {
                answer.push_back(currSub);
            } else {
                // too much! reduce time and put it back on stack
                remaining.push(make_pair(currSub, currTime - nextStart));
            }
        }
    }
    
    // do it for last elem
    answer.push_back(plans[plans.size() - 1][0]);
    
    // deal with everything in stack
    while (remaining.size() > 0) {
        const auto& curr = remaining.top();
        remaining.pop();
        answer.push_back(curr.first);
    }
    
    return answer;
}

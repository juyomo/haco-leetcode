// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/131704
// Solved on Wed, June 4, 2025

#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int frontOfLine = 1;
    int nextWantedIdx = 0;
    stack<int> helper;
    
    while (nextWantedIdx < order.size()) {
        int nextWanted = order[nextWantedIdx];
        if (frontOfLine == nextWanted) {
            frontOfLine++;
            nextWantedIdx++;
        } else if (nextWanted > frontOfLine) {
            // load from main to helper
            while (nextWanted != frontOfLine) {
                helper.push(frontOfLine);
                frontOfLine++;
            }
            frontOfLine++;
            nextWantedIdx++;
        } else if (helper.size() > 0 && nextWanted == helper.top()) {
            // box we want is in stack, and it needs to be at top
            helper.pop();
            nextWantedIdx++;
        } else {
            return nextWantedIdx;
        }
    }
    
    return nextWantedIdx;
}

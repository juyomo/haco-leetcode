// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/138476
// Solved on: June 8, 2025 (part of HOCO-LeetCode study).

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> countPerSize;
    for (int n : tangerine) {
        countPerSize[n]++;
    }
    
    vector<int> sizes;
    for (const auto& p : countPerSize) {
        sizes.push_back(p.second);
    }
    
    sort(sizes.begin(), sizes.end());
    
    for (int i = sizes.size() - 1; i >- 0; i--) {
        k -= sizes[i];
        if (k <= 0) {
            return sizes.size() - i;
        }
    }
    
    return sizes.size();
}

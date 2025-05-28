// Author: Juyoung Moon
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {

        // STEP 1. If there are more than 3 of the same number, bring it down to 3.
        unordered_map<int, int> counts;
        for (int i = 0; i < num.size(); i++) {
            if (counts[num[i]] < 3) {
                counts[num[i]]++;
            }
        }

        vector<int> nums;
        for (const auto& p : counts) {
            for (int j = 0; j < p.second; j++) {
                nums.push_back(p.first);
            }
        }

        // STEP 2. Make a hashmap of indices.
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        // STEP 3. Find triplets.
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int lookFor = -1 * (nums[i] + nums[j]);
                if (indices.find(lookFor) != indices.end() && indices[lookFor] != i && indices[lookFor] != j) {
                    res.push_back({lookFor, nums[i], nums[j]});
                }
            }
        }

        // STEP 4. Remove duplicates.
        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            return res;
        }

        vector<vector<int>> ans;
        ans.push_back(res[0]);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] != res[i-1]) {
                ans.push_back(res[i]);
            }
        }
        return ans;
    }
};

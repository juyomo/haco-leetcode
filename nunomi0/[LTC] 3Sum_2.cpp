class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break; // 모두 양수인 경우 불가능
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 중복되는 수는 pass
            int l = i + 1, r = nums.size() - 1;
            while (l < r) { // two pointer
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) { // 중복되는 수는 pass
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

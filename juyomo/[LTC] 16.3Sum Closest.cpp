// Author: Juyoung Moon
// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Method 1. O(n^2)
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
                
            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];
                if (currSum == target) {
                    return currSum;
                } else if (currSum < target) {
                    l++;
                } else if (currSum > target) {
                    r--;
                }
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }
            }
        }

        return closestSum;

        // Method 2. Brute force.
        /*
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int num2 = nums[j];
                for (int k = j + 1; k < nums.size(); k++) {
                    int currSum = num1 + num2 + nums[k];
                    if (abs(currSum - target) < abs(closestSum - target)) {
                        closestSum = currSum;
                    }
                }
            }
        }

        return closestSum;
        */
    }
};

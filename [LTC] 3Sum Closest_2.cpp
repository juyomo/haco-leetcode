class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++){
            int l = i+1;
            int r = nums.size()-1;
            while (l<r){
                int tmp = nums[i]+nums[l]+nums[r];
                if (abs(target-tmp)<abs(target-ans)) ans=tmp;
                if (tmp==target) break;
                else if (tmp>target) r--;
                else l++;
            }
        }
        return ans;
    }
};

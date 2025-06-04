class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++){
            for (int j = i+1; j<nums.size(); j++){
                int s = j+1;
                int e = nums.size()-1;
                while (s<=e){
                    int m = (s+e)/2;
                    int tmp = nums[i]+nums[j]+nums[m];
                    if (abs(target-tmp)<abs(target-ans)) ans=tmp;
                    if (tmp==target) break;
                    else if (tmp>target) e=m-1;
                    else s=m+1;
                }
            }
        }
        return ans;
    }
};

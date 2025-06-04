class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());

        for (int i = 0; i<nums.size(); i++){
            for (int j = i+1; j<nums.size(); j++){

                // binary search
                int s = j+1;
                int e = nums.size()-1;
                int target = -(nums[i]+nums[j]);
                while (s<=e){
                    int m = (s+e)/2;
                    if (nums[m]==target){
                        vector<int> v = {nums[i],nums[j],nums[m]};
                        st.insert(v);
                        break;
                    }
                    else if (nums[m]>target) e=m-1;
                    else s=m+1;
                }
            }
        }

        vector<vector<int>> ans;
        for (auto iter=st.begin(); iter!=st.end(); iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};

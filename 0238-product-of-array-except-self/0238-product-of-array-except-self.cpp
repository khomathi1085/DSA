class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int pre=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=pre;
            pre*=nums[i];
        }
        int suf=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=suf;
            suf*=nums[i];
        }
        return ans;
    }
};
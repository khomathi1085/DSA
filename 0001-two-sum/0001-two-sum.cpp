class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.find(target-nums[i])==ans.end()){
                ans[nums[i]]=i;
            }
            else{
                return {i,ans[target-nums[i]]};
            }
        }
        return {};
    }
};
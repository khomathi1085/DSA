class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ans;
        int major=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            if(ans.find(nums[i])==ans.end()){
                ans[nums[i]]=1;
            }
            else{
                ans[nums[i]]++;
            }
            if(ans[nums[i]]>major){
                return nums[i];
            }
        }
        return -1;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majority=n/2;
        unordered_map<int,int> ans;
        for(int i=0;i<n;i++){
            if(ans.find(nums[i])==ans.end()){
                if(n==1){
                    return nums[i];
                }
                ans[nums[i]]=1;
            }
            else{
                ans[nums[i]]++;
                if(ans[nums[i]]>majority){
                    return nums[i];
                }
            }
        }
        return 0;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        int maxSum=0;
        while(low<=high){
            int sum=nums[low]+nums[high];
            maxSum=max(sum,maxSum);
            low++;;
            high--;
        }
        return maxSum;
    }
};
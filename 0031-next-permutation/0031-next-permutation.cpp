class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pivot=i-1;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int nextgreater;
            for(int i=nums.size()-1;i>pivot;i--){
                if(nums[i]>nums[pivot]){
                    nextgreater=i;
                    break;
                }
            }
            swap(nums[pivot],nums[nextgreater]);
            reverse(nums.begin()+pivot+1,nums.end());
        }

    }
};
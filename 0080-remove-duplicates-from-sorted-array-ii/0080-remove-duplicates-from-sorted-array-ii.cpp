class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int unique=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[unique-2]){
                nums[unique]=nums[i];
                unique++;
            }
        }
        return unique;
    }
};
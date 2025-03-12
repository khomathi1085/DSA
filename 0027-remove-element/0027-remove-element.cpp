class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int unique=0;
        for(int num : nums){
            if(num!=val){
                nums[unique]=num;
                unique++;
            }
        }
        return unique;
    }
};
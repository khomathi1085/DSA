class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityNum=(nums.size()-1)/2;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            if(map[nums[i]]>majorityNum) return nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string max = *max_element(strs.begin(),strs.end());
        string min = *min_element(strs.begin(),strs.end());
        int i=0;
        string ans="";
        while(i<min.size()){
            if(min[i]==max[i]){
                ans+=min[i];
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
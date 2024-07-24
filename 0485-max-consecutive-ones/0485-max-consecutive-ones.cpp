class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int len=0;
        int maxLen=0;
        while(j<nums.size()){
            
            if(nums[j]==1){
                len++;
            }else{
            maxLen=max(maxLen,len);
                len=0;
            }
            
            j++;
        }
        maxLen=max(maxLen,len);
        return maxLen;
    }
};
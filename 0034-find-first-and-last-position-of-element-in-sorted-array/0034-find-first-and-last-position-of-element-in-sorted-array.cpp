class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=-1, right=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(left==-1) left=i;
                
                right=i;
            }
        }
        return {left,right};
    }
};
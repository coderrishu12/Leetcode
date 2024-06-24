class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Approach 2
        int left=-1, right=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(left==-1) left=i;
                
                right=i;
            }
        }
        return {left,right};
        
        //Approach 1
        
       //int lb= (lower_bound(nums.begin(),nums.end(),target)- nums.begin());
        // int ub= ( upper_bound(nums.begin(),nums.end(),target ) - nums.begin()-1); 
        // if(lb<=ub){
        //     return {lb,ub};
        // } 
        // return {-1,-1};
    }
};
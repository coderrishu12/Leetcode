class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<=4) return 0;
        
        sort(nums.begin(), nums.end());
        int mini1= nums[n-4]-nums[0];
        int mini2= nums[n-3]-nums[1];       
        int mini3= nums[n-2]-nums[2];
        int mini4= nums[n-1]-nums[3];
        
        int mini5 = min(min(mini1,mini2), min(mini3,mini4));
        return mini5;
        
    }
};
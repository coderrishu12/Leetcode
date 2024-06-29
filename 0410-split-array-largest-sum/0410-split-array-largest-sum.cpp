Same as Book allocation Problem


class Solution {
public:
    int canAccumulate(vector<int>& nums, int mid){
        int cnt=1, splitsSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+splitsSum<=mid){
                splitsSum+=nums[i];
            }else{
                cnt++;
                splitsSum=nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high=accumulate(nums.begin(), nums.end(), 0);
        // int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(canAccumulate(nums, mid)>k){
                // ans= mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};

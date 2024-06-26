class Solution {
public:
    bool search(vector<int>& nums, int target) {
//         Approach 2 Binary Search
        int low=0, high=nums.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++, high--;
                continue;
            }
            
            if(nums[low]<=nums[mid]){
                if(target<=nums[mid] && nums[low]<=target){
                    high=mid-1;
                }else {
                    low=mid+1;
                }
            }else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
        
        
        
//          Approach 1 (Brute Force)
//         unordered_map<int, int> mp;
        
//         for(auto &ele:nums){
//             mp[ele]++;
//             if(mp[target ]>=1 ){
//                 return true;
//             }
//         }
//         return false;
    }
};
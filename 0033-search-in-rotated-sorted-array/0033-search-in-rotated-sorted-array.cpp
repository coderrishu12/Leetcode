class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Approach 2 Binary Search
        int low=0, high=nums.size()-1;
        
        while(low<=high){
            int mid= low+(high-low)/2;
            
            if(nums[mid]==target) return mid;
            
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
        return -1;
        
        
        
        
        
        
        // Approach 1 Linear Search O(n)
        
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;
    }
};
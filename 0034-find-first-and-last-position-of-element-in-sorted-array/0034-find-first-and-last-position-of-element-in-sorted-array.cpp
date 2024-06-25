class Solution {
public:
    int Righti(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target){
                last=mid, low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;
    }
    int Lefti(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target){
                first=mid, high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      return {Lefti(nums,target), Righti(nums,target)};
        
        
        //Approach 2
//         int left=-1, right=-1;
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 if(left==-1) left=i;
                
//                 right=i;
//             }
//         }
//         return {left,right};
        
        //Approach 1
        
       //int lb= (lower_bound(nums.begin(),nums.end(),target)- nums.begin());
        // int ub= ( upper_bound(nums.begin(),nums.end(),target ) - nums.begin()-1); 
        // if(lb<=ub){
        //     return {lb,ub};
        // } 
        // return {-1,-1};
    }
};
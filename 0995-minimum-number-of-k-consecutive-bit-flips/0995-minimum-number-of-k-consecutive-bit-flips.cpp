class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Approach 3(same as Approacj 3, only here we are removing some extra space to reduce our space complexity)
        int n=nums.size();
            int flips=0;
            
        int flipCountFromPastFori =0;
        // vector<bool> isFlipped(n,false);
        
        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==5){
                flipCountFromPastFori--;
            }
            
            if(flipCountFromPastFori %2 == nums[i]){
                
                if(i+k>n){
                    return -1;
                }
                flipCountFromPastFori++;
                flips++;
                nums[i]=5;
            }
        }
        return flips;
        
        
        //         Approach 2
//             int n=nums.size();
//             int flips=0;
            
//         int flipCountFromPastFori =0;
//         vector<bool> isFlipped(n,false);
        
//         for(int i=0;i<n;i++){
//             if(i>=k && isFlipped[i-k]==true){
//                 flipCountFromPastFori--;
//             }
            
//             if(flipCountFromPastFori %2 == nums[i]){
                
//                 if(i+k>n){
//                     return -1;
//                 }
//                 flipCountFromPastFori++;
//                 flips++;
//                 isFlipped[i]=true;
//             }
//         }
//         return flips;
        
        
        
//         Brute Force (TLE) O(N*k) 
//         int i=0;
//         int count=0;
//         while(i<nums.size()){
            
//             if(nums[i]==0 && i+k-1<nums.size()){
//                 count++;
//                for(int l=i;l<=i+k-1;l++){
//                    nums[l]=1-nums[l];
//                } 
//             }else if(nums[i]==0 && i+k-1>=nums.size()){
//                 return -1;
//                 break;
//             }else if(nums[i]==1){
//                 i++;
//             }  
                
//         }
//         return count ;
    }
};
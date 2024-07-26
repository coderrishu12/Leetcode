class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int i=0,j=0;
        int len=0;
        int zeroes=0;
        int maxLen=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[i]==0){
                    zeroes--;
                }
                i++;
            }
            if(zeroes<=k){
                len = (j-i+1);
                maxLen=max(maxLen, len);
            }
            
            
            
            j++;
        }
        return maxLen;
        
//         Approach 1
//         int i=0,j=0;
//         int lenZer=0;
//         int lenOne=0;
//         int maxLen=0;
//         while(j<nums.size()){
//             if(nums[j]==1){
//                 lenOne++;
//             }else{
//                 lenZer++;
//             }
//             while(lenZer>k){
//                 if(nums[i]==0){
//                     lenZer--;
//                 }else{
//                     lenOne--;
//                 }
//                     i++;
//             }
            
            
//             maxLen=max(maxLen, lenOne+lenZer);
//             j++;
//         }
//         return maxLen;
    }
};
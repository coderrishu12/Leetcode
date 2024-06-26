class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k=3;
        int n=nums.size();
        
            int flips=0;
            
        int flipCountFromPastFori =0;
        vector<bool> isFlipped(n,false);
        
        for(int i=0;i<n;i++){
            if(i>=k && isFlipped[i-k]==true){
                flipCountFromPastFori--;
            }
            
            if(flipCountFromPastFori %2 == nums[i]){
                
                if(i+k>n){
                    return -1;
                }
                flipCountFromPastFori++;
                flips++;
                isFlipped[i]=true;
            }
        }
        return flips;
        
    }
};
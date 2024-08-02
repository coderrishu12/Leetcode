class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int totalOnes = count(nums.begin(), nums.end(), 1);
        int maxi = INT_MAX;
        int currOnes=0;
        while(j<2*n){
            
            if(j-i+1 >totalOnes){
                if(nums[i%n]==1){
                    currOnes--;
                }
                (i++)%n;
            }
            
            if(nums[j%n]==1){
                currOnes++;
            }
            int diff = totalOnes-currOnes;
            maxi = min(maxi, diff);
            (j++)%n;
        }
        return maxi;
        
    }
};
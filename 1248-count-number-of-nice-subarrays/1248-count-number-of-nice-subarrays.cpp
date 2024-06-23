class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int i=0;
        int j=0;
        long sum=0;
        int count=0;
        
        while(j<nums.size()){
            sum+=(nums[j]%2);
            while(sum>k){
                sum=sum-(nums[i]%2);
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
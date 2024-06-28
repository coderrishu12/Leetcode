class Solution {
public:
   long long func(vector<int>& piles, int hour){
        long long totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours+=ceil((double)piles[i]/(double)hour);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int low=1,  high= *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid= low+(high-low)/2;
            long long totalHours=func(piles, mid);
            if(totalHours<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
       
       
    }
};
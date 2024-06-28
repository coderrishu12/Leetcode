class Solution {
public:
    int canMakeBouq(vector<int>& bloomDay, int mid, int k){
        int consecutive_count=0;
        int bouq_count=0;
        
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consecutive_count++;
            }else{
                consecutive_count=0;
            }
            if(consecutive_count>=k){
                bouq_count++;
                consecutive_count=0;
            }
        }
        return bouq_count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start_day=1;
        int end_day= *max_element(bloomDay.begin(), bloomDay.end());
        int minDays=-1;
        while(start_day<=end_day){
            int mid=start_day+(end_day-start_day)/2;
            
            if(canMakeBouq(bloomDay, mid,k)>=m){
                minDays=mid;
                end_day=mid-1;
            }else{
                start_day=mid+1;
            }
        }
        return minDays;
    }
};
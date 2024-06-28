class Solution {
public:
    int func(vector<int>& weights, int days,int mid){
        int day=1, load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i] > mid){
                day++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        long long sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int high=sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            int daysReq=func(weights,days,mid);
            if(daysReq<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
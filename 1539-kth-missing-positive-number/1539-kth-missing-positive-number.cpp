class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            int missing= arr[mid] - mid-1;
            if(missing<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
        
//         Approach 1(Brute Force)
//         int K=k;
    
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]<=K) K++;
//             else break;
//         }
//         return K;
    }
};
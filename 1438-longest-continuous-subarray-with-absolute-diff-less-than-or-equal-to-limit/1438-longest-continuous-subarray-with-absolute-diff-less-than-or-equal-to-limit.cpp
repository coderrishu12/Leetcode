class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
// Better Approach with the help of Heaps
           int n=nums.size();
        
        priority_queue<P, vector<P>> maxpq;
        priority_queue<P, vector<P>, greater<P>> minpq;
        
        int i=0, j=0,maxLen=0;
        
        while(j<n){
            maxpq.push({nums[j],j});
            minpq.push({nums[j],j});
            
            while(maxpq.top().first-minpq.top().first>limit){
                i=min(maxpq.top().second, minpq.top().second)+1;
                
                while(maxpq.top().second<i){
                    maxpq.pop();
                }
                while(minpq.top().second<i){
                    minpq.pop();
                }
            }
            maxLen=max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
        
        
        
//         Time limit exceed
//         int i=0, j=0;
//          int maxi=INT_MIN;
//         int sub=-1;
//         int maxi2=INT_MIN;
//         int n=nums.size();
//         while(j<nums.size()){
           
//             auto maxEle= *max_element(nums.begin()+i, nums.end()-(n-1-j));
//             auto minEle= *min_element(nums.begin()+i, nums.end()-(n-1-j));
//             sub= abs(maxEle-minEle);
//                 if(sub<=limit){
//                     j++;
//                 }else{
//                     i++;
//                 }
//             maxi=max(maxi,j-i+1);
            
//         }
//         // cout<<maxi<<" "<<(j-i+1)<<endl;
//         return maxi-1;
    }
};
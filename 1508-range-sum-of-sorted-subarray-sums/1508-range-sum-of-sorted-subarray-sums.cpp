class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int j=0;
            
        for(int i=1;i<=n;i++){
            int sum=0;
            while(j<n){
                sum+=nums[j];
                ans.push_back(sum%mod);
                j++;
            }
            j=i;
        }
        int result=0;
        sort(ans.begin(), ans.end());
        for(int i=left-1;i<right;i++){
            cout<<ans[i]<<" ";
            result=(result + ans[i])%mod;
        }
        return result%mod;
    }
};
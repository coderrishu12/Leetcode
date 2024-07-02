class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001]={0};
        int n=nums1.size();
        for(auto x: nums1){
            freq[x]++;
        }
        vector<int> ans;
        for(auto x:nums2){
            
            if(freq[x]>0){
                freq[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(auto &ele:nums){
            mp[ele]++;
            if(mp[ele]>=1 && ele==target){
                return true;
            }
        }
        return false;
    }
};
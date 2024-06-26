class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(auto &ele:nums){
            mp[ele]++;
            if(mp[target ]>=1 ){
                return true;
            }
        }
        return false;
    }
};
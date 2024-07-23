class Solution {
public:
   static bool sortByFrequency(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end() , sortByFrequency);
        
        vector<int> ans;
        for(auto &it: vec){
            while(it.second--){
            ans.push_back(it.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int ele=pq.top().first;
            pq.pop();
            ans.push_back(ele);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> pq;
        
        while(!names.empty()){
            pq.push({heights.back(), names.back()});

            names.pop_back();
            heights.pop_back();
        }
        vector<string> ans;
        while(!pq.empty()){
            string res1 = pq.top().second;
            pq.pop();
            ans.push_back(res1);
        }
        
        return ans;
    }
};
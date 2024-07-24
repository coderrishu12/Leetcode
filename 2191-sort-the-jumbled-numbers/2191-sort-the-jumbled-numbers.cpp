class Solution {
public:
    string getMappedNum(string &num, vector<int> &mapping){
        string mappedStr = "";
        for(int i = 0; i<num.length();i++){
            char ch = num[i];
            int idx = ch-'0';
            mappedStr += to_string(mapping[idx]);
        }
        return mappedStr;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> vec;
        
        for(int i=0;i<n;i++){
            string numStr = to_string(nums[i]);
            
            string mappedNum = getMappedNum(numStr, mapping);
            
            int numIntoInt = stoi(mappedNum);
            vec.push_back({numIntoInt , i});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int> result;
        
        for(auto &p: vec){
            int originalIdx = p.second;
            result.push_back(nums[originalIdx]);
        }
        return result;
        
    }
};
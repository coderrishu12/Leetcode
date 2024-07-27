class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0, cnt=0;
        int maxLen=INT_MIN;
        unordered_map<int, int> mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            
            if(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
                }
                i++;
            }
            maxLen=max(maxLen,j-i+1);
                    
            j++;
            
        }
            
        return maxLen;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();
        
        int result = 0;
        
        for(int i=1;i<arrays.size();i++){
            int currMIN = arrays[i].front();
            int currMAX = arrays[i].back();
            
            result = max({result, abs(currMIN-MAX), abs(currMAX - MIN)});
            
            MAX = max(currMAX, MAX);
            MIN = min(currMIN, MIN);
        }
        return result;
    }
};
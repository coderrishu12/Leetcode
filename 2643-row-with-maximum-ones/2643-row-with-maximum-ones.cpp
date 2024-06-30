class Solution {
public:
  
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       int maxi = 0, index = 0;
        int m = mat.size();    
        int n = mat[0].size(); 

        for (int i = 0; i < m; ++i) {
            int cntOnes = 0;
            for(int j=0;j<n;j++){
                cntOnes+=mat[i][j];
            }
            
            if (cntOnes > maxi) {
                maxi = cntOnes;
                index = i;
            }
        }
        
        return {index, maxi};
    }
};
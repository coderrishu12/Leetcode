class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(target==matrix[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
};
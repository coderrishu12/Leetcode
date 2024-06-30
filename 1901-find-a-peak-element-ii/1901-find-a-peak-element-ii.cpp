class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col){
        int maxVal=-1;
        int index=-1;
        
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxVal){
                maxVal=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxRowIdx = findMaxIndex(mat,n,m,mid);
            int left = mid-1 >= 0 ? mat[maxRowIdx][mid-1] : -1;
            int right = mid+1 < m  ? mat[maxRowIdx][mid+1] : -1;
            if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right){
                return {maxRowIdx,mid};
            }
            else if(mat[maxRowIdx][mid] < left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
        
            
    }
};
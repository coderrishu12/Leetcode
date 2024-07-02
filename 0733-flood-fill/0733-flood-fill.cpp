class Solution {
public:
    void DFS(vector<vector<int>>& grid,vector<vector<int>>& ans, int sr, int sc, int &color, int &temp){
        ans[sr][sc]=color;
        int n = grid.size();
        int m = grid[0].size();
       int drow[] = {-1,0,+1,0};
         int dcol[] = {0,+1,0,-1};
       
            for(int i=0;i<4;i++){
                int nrow = sr+drow[i];
                int ncol = sc+dcol[i];
                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && ans[nrow][ncol]!=color && grid[nrow][ncol]==temp){
                   
                    DFS(grid, ans, nrow,ncol, color, temp );
                }
            }
        }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int temp=image[sr][sc];
        vector<vector<int>> ans=image;
        
            DFS(image, ans, sr,sc, color, temp );
        
        return ans;
    }
};
// Same as Number of provinces leetcode-547


class Solution {
public: 
    void DFS(vector<vector<char>>& grid, int &row, int &col, vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
    
        for (int d = 0; d < 4; ++d) {
            int nrow = row + dr[d];
            int ncol = col + dc[d];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
            DFS(grid, nrow, ncol, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                cnt++;
                DFS(grid,i,j,vis);
                }    
            }
        }
        return cnt;
    }
};
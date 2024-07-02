class Solution {
public:
    void DFS(int row, int col, vector<vector<char>>& grid){
        grid[row][col]='1';
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        
        for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol]=='O'){
                    DFS(nrow,ncol,grid);
                }
            }
    }
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O'){
                DFS(0,j,grid);
            }
            if(grid[n-1][j]=='O'){
                DFS(n-1,j,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O'){
                DFS(i,0,grid);
            }
            if(grid[i][m-1]=='O'){
                DFS(i,m-1,grid);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }else if(grid[i][j]=='1'){
                    grid[i][j]='O';
                }
            }
        }
        
        
    }
};
class Solution {
public:
    vector<vector<int>> directions{{-1,-1},{-1,0}, {-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         Approach 3 by Queue
        int m=grid.size();
            int n=grid[0].size();

            if(m==0 || n==0 || grid[0][0]!=0){
                return -1;
            }

            auto isSafe=[&](int x, int y){
                return x>=0 && x<m && y>=0 && y<n;

            };
            vector<vector<int>> result(m, vector<int>(n, INT_MAX));
            queue<P> pq;
            pq.push({0, {0,0}});
            result[0][0]=0;
        
        while(!pq.empty()){
            int d = pq.front().first;
            pair<int, int> node = pq.front().second;
            int x= node.first;
            int y= node.second;
            pq.pop();
            
            for(auto dir: directions){
                int x_ = x+ dir[0];
                int y_ = y+ dir[1];
                
                int dist=1;
                
                if(isSafe(x_, y_) && grid[x_][y_]==0 && d+dist < result[x_][y_]){
                    pq.push({d+dist, {x_,y_}});
                    result[x_][y_]=d+dist;
                }
            }
        }
        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }
        return result[m-1][n-1]+1;
        
        
//         Approach 2 by Dijkstra Algorithm
        
//             int m=grid.size();
//             int n=grid[0].size();

//             if(m==0 || n==0 || grid[0][0]!=0){
//                 return -1;
//             }

//             auto isSafe=[&](int x, int y){
//                 return x>=0 && x<m && y>=0 && y<n;

//             };
//             vector<vector<int>> result(m, vector<int>(n, INT_MAX));
//             priority_queue<P, vector<P>, greater<P>> pq;
//             pq.push({0, {0,0}});
//             result[0][0]=0;
        
//         while(!pq.empty()){
//             int d = pq.top().first;
//             pair<int, int> node = pq.top().second;
//             int x= node.first;
//             int y= node.second;
//             pq.pop();
            
//             for(auto dir: directions){
//                 int x_ = x+ dir[0];
//                 int y_ = y+ dir[1];
                
//                 int dist=1;
                
//                 if(isSafe(x_, y_) && grid[x_][y_]==0 && d+dist < result[x_][y_]){
//                     pq.push({d+dist, {x_,y_}});
//                     result[x_][y_]=d+dist;
//                 }
//             }
//         }
//         if(result[m-1][n-1]==INT_MAX){
//             return -1;
//         }
//         return result[m-1][n-1]+1;
        
//         Approach 1 by BFS
//         int m=grid.size();
//         int n=grid[0].size();
        
//         if(m==0 || n==0 || grid[0][0]!=0){
//             return -1;
//         }
        
//         auto isSafe=[&](int x, int y){
//             return x>=0 && x<m && y>=0 && y<n;
               
//         };
//         queue<pair<int, int>> q;
//         q.push({0,0});
//         grid[0][0]=1;
        
//         int level=0;
//         while(!q.empty()){
//             int N=q.size();
//             while(N--){
//                 auto curr=q.front();
//                 q.pop();
//                 int x=curr.first;
//                 int y=curr.second;
                
//                 if(x==m-1 && y==n-1){
//                     return level+1;
//                 }
//                 for(auto dir: directions){
//                     int _x = x+dir[0];
//                     int _y = y+dir[1];
                    
//                     if(isSafe(_x,_y) && grid[_x][_y]==0){
//                         q.push({_x,_y});
//                         grid[_x][_y]=1;
//                     }
//                 }
//             }
//             level++;
//         }
//         return -1;
    }
};
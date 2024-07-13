class Solution {
public:
//     vector<int> parent;
//     int find(int X){
//         if(parent[X]==X){
//             return X;
//         }
//         return parent[X]=find(parent[X]);
//     }
    
//     void Union(int x, int y){
        
//         int parent_x=find(x);
//         int parent_y=find(y);
//         if(parent_x!=parent_y) parent[parent_y]=parent_x;
//     }
    void dfs(vector<vector<int>>& stones, int idx, vector<bool>& vis){
        vis[idx]=true;
        
        for(int i=0;i<stones.size();i++){
            if(!vis[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                dfs(stones, i, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
//       Approach 2 By DFS
        int n=stones.size();
        vector<bool> vis(n, false);
        int groups = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            
            dfs(stones, i, vis);
            groups++;
        }
        return n-groups;
        
        
        
//          Approach 1 By DSU        
//         int n=stones.size();
//         parent.resize(n);
        
//         for(int i=0;i<n;i++){
//             parent[i]=i;
            
//         }
        
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
//                     Union(i,j);
//                 }
//             }
//         }

//         int grps=0;
//         for(int i=0;i<n;i++){
//             if(parent[i]==i) grps++;
//         }
//         return n-grps;
    }
};
class Solution {
public:
    void DFS(int ancestors, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result){
        for(auto &ngbr:adj[currNode]){
            if(result[ngbr].empty() || result[ngbr].back()!=ancestors){
                result[ngbr].push_back(ancestors);
                DFS(ancestors, adj, ngbr, result);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            int ancestors = i;
            DFS(ancestors,adj,i,result);
        }
        return result;
    }
};
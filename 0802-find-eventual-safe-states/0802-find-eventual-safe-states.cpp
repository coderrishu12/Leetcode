class Solution {
public:
    bool isCyclicDFS(vector<vector<int>>& graph,  vector<int>& vis, int u){
        vis[u]=2;
        
        
        for(auto &v: graph[u]){
            if(vis[v]==0 && isCyclicDFS(graph, vis, v)==true){
                return true;
            }else if(vis[v]==2){
                return true;
            }
        }
        vis[u]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> vis(n,0);
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0 && isCyclicDFS(graph, vis, i)==0){
                continue;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;

    }
};
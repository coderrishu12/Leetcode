class Solution {
public:
    bool isCyclicDFS(vector<vector<int>>& graph,  vector<int>& vis, vector<int>& dfsVis, int u){
        vis[u]=1;
        dfsVis[u]=1;
        
        for(auto &v: graph[u]){
            if(vis[v]==0 && isCyclicDFS(graph, vis, dfsVis, v)==true){
                return true;
            }else if(dfsVis[v]==1){
                return true;
            }
        }
        dfsVis[u]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0 && isCyclicDFS(graph, vis, dfsVis, i)==0){
                continue;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfsVis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};
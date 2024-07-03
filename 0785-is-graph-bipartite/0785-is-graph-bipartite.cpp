class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr]=currColor;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkBipartiteDFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor){
        color[curr]=currColor;
            
            for(auto v: graph[curr]){
                if(color[v]==-1){
                    color[v]=1-color[curr];
                    if(checkBipartiteDFS(graph ,v,color, color[v])==false){
                        return false;
                    }
                }else if(color[v]==color[curr]){
                    return false;
                }
            }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
            for(int i=0;i<n;i++){
                if(color[i]==-1){
                 if(checkBipartiteDFS(graph, i, color, 1)==false){
                     return false;
                 }   
                }
            }
        return true;
    }
};
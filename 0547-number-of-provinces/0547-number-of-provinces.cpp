class Solution {
public:int n;
    void BFS(vector<vector<int>>& isConnected, int node, vector<bool> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            for(int i=0;i<n;i++){
                if(isConnected[it][i]==1 && !vis[i] ){
                    BFS(isConnected, i, vis);
                }
            }
            
        }
    }
    void DFS(vector<vector<int>>& isConnected, int node, vector<bool> &vis){
        vis[node]=1;

        for(int i=0;i<n;i++){
            if(!vis[i] && isConnected[node][i]==1){
                DFS(isConnected,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int cnt=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                BFS(isConnected, i, vis);
            }
        }
        return cnt;
        
    }
};
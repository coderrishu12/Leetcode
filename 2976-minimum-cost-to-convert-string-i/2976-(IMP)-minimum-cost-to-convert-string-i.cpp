class Solution {
public: typedef long long ll;
    void floydWarshall( vector<vector<ll>> &adj, vector<char>& original, vector<char>& changed, vector<int>& cost){
        
        for(int i=0;i<original.size();i++){
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            
            adj[s][t] = min(adj[s][t], (ll)cost[i]);
        }
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        
    }
    
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector <vector<ll>> adj(26,vector<ll>(26,INT_MAX));
        
        floydWarshall(adj, original, changed, cost);
        
        ll ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            
            if(adj[source[i] -'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            
            ans+=adj[source[i] -'a'][target[i]-'a'];
        }
        return ans;
        
    }
};

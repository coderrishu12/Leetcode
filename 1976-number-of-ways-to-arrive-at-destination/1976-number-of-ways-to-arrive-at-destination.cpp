class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
   const long long mod=1e9+7;
        vector<long long> destinations(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        vector<pair<long long,long long>> adj[n];
        
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        priority_queue<pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long,long long>>>  q;
        q.push({0,0});
        destinations[0]= 0;
        ways[0]=1;
        
        while(!q.empty()){
           long long d = q.top().first;
           long long u = q.top().second;
            q.pop();
            
            for(auto vec: adj[u]){
                long long v    = vec.first;
                long long dist = vec.second;
                
                if(destinations[v] > (d+dist)){
                    ways[v]=ways[u];
                    destinations[v] = d+dist;
                    q.push({ destinations[v] , v});
                }else if(d+dist == destinations[v]){
                    ways[v]=(ways[v]+ways[u])%mod;
                }                
            }
        }
        
        return ways[n-1]%mod;
    }
};
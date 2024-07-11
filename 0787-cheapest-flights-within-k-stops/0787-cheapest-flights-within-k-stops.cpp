class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec: flights){
            int from = vec[0];
            int to   = vec[1];
            int cost = vec[2];
            
            adj[from].push_back({to, cost});
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        result[src]= 0;
        
        int steps  = 0;
        
        while(!q.empty() && steps<=k){
            int N=q.size();
           while(N--){
                auto from   = q.front().first;
                auto fromCost = q.front().second;
                q.pop();

                for(pair<int,int> &vec: adj[from]){
                    auto to     = vec.first;
                    auto toCost = vec.second;

                    if( result[to] > fromCost + toCost){
                        result[to] = fromCost + toCost;
                        q.push({to,fromCost + toCost });
                    }
                }
           }
            steps++;
        }
        
        return result[dst]==INT_MAX ? -1: result[dst];
        
    }
};
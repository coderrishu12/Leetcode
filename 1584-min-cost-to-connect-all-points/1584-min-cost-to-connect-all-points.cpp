class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<P>> adj(V);
        
            for(int i=0;i<V;i++){
                for(int j=i+1;j<V;j++){
                    
                    int x1 = points[i][0];
                    int y1 = points[i][1];

                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int dist = abs(x1-x2)+abs(y1-y2);

                    adj[i].push_back({j, dist});
                    adj[j].push_back({i, dist});
                }
            }
            
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0,0});
            vector<bool> inMST(V, false);
            int sum=0;
            
            while(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                
                int dist = p.first;
                int node = p.second;
                
                if(inMST[node]==true){
                    continue;
                }
                inMST[node]=true;
                sum+=dist;
                
                for(auto &temp: adj[node]){
                    int neighbour = temp.first;
                    int neighbour_wt = temp.second;
                    
                    if(inMST[neighbour] == false){
                        pq.push({neighbour_wt, neighbour});
                    }
                }
            }
        
         return sum;
        
    }
};
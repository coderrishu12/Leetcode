class Solution {
public:
    vector<vector<int>> directions={{-1,0},{1,0}, {0,-1},{0,1}};
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
            int m=heights.size();
            int n=heights[0].size();

            vector<vector<int>> result(m, vector<int>(n, INT_MAX));
            priority_queue<P, vector<P>, greater<P>> pq;
        
            auto isSafe=[&](int x, int y){
                return x>=0 && x<m && y>=0 && y<n;

            };
            result[0][0]=0;
            pq.push({0, {0,0}});
        
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();
            int x= node.first;
            int y= node.second;
            
            for(auto &dir: directions){
                int x_ = x+ dir[0];
                int y_ = y+ dir[1];
                
                if(isSafe(x_, y_) ){
                    int absDiff =abs(heights[x][y]-heights[x_][y_]);
                    int maxi = max(d, absDiff);
                    
                    if(result[x_][y_] > maxi){
                    result[x_][y_]=maxi;
                    pq.push({maxi, {x_,y_}});                        
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
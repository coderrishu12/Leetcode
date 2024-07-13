class Solution {
public:
    vector<int> parent;
    int find(int X){
        if(parent[X]==X){
            return X;
        }
        return parent[X]=find(parent[X]);
    }
    
    void Union(int x, int y){
        
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x!=parent_y) parent[parent_y]=parent_x;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        int grps=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) grps++;
        }
        return n-grps;
    }
};
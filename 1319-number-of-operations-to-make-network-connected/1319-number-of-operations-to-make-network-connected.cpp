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
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int m=connections.size();
        
        if(m<n-1){
            return {-1};
        }
        
        for(auto temp: connections){
            int u = temp[0];
            int v = temp[1];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u!=parent_v){
                Union(u,v);
                n--;
            }else{
                continue;
            }
        }
        return n-1;
    }
};
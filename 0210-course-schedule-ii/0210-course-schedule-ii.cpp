class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         queue<int> q;
        vector<int> indegree(n,0);
        
        for(auto &v: prerequisites){
            int a = v[0];
            int b = v[1];;
                indegree[a]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            
            for(auto &v: prerequisites){
                 int a = v[0];
                 int b = v[1];
                if(u==b){
                    indegree[a]--;
                    if(indegree[a]==0){
                        q.push(a);
                    }
                }
            }
        }
        // reverse(result.begin(),result.end());
        return result.size()==n ? result : vector<int>();
    }
};
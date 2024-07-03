class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         queue<int> q;
        vector<int> indegree(n,0);
        
        for(auto &v: prerequisites){
            int a = v[0];
            int b = v[1];;
                indegree[b]++;
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
                if(u==a){
                    indegree[b]--;
                    if(indegree[b]==0){
                        q.push(b);
                    }
                }
            }
        }
        reverse(result.begin(),result.end());
        return result.size()==n ? result : vector<int>();
    }
};
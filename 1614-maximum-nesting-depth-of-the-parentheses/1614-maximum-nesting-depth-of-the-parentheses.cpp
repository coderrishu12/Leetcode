class Solution {
public:
    int maxDepth(string s) {
        stack<char> q;
        int maxi = 0;
        for(auto &ch: s){
            if(ch == '('){
                q.push(ch);
            }else if(!q.empty() && ch==')'){
                maxi = max(maxi, (int)q.size());
                q.pop();
            }
        }
        return maxi;
        
    }
};
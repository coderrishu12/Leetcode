class Solution {
public:
    int countSeniors(vector<string>& s) {
        
        int cnt=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i][11]==(char)'6' && s[i][12]>(char)'0'){
                cnt++;
            }
            else if(s[i][11]>'6'){
                cnt++;
            }
            
        }
        return cnt;
    }
};
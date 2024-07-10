class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int sum=0;
        
        for(auto &log:logs){
            
                if(log=="../"){
                    sum=max(0,sum-1);
                }else if(log== "./"){
                    continue;
                }else{
                    sum++;
                }
            
        }
        return sum;
    }
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        int teams=0;
        
        for(int j=1;j<n-1;j++){
            int cntSL = 0;
            int cntLL = 0;
            int cntSR = 0;
            int cntLR = 0;
            
            for(int i=0;i<j;i++){
                if(rating[i]>rating[j]){
                    cntLL++;
                }else if(rating[i]<rating[j]){
                    cntSL++;
                }
            }
            
            for(int i=j+1;i<n;i++){
                if(rating[i]>rating[j]){
                    cntLR++;
                }else if(rating[i]<rating[j]){
                    cntSR++;
                }
            }
            teams+=(cntLL * cntSR) + (cntSL * cntLR);
        }
        return teams;
    }
};
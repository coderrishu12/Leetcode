class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec(n+1);
        
        int i2=1, i3=1, i5=1;
        vec[1]=1;
        
        for(int i=2;i<=n;i++){
            int i2U = vec[i2]*2;
            int i3U = vec[i3]*3;
            int i5U = vec[i5]*5;
            int minU = min({i2U, i3U, i5U});
            vec[i] = minU;
            if(minU == i2U){
                i2++;
            }
            if(minU == i3U){
                i3++;
            }
            if(minU == i5U){
                i5++;
            }
        }
       
        return vec[n];
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;
        int lSum=0, rSum=0;
        int len=k;
        int maxSum=0;
        
        for(int i=0;i<len;i++){
            lSum +=cardPoints[i];
        }
        maxSum = max(maxSum, lSum);
        int rIdx = cardPoints.size()-1;
        for(int i = k-1;i>=0;i--){
            lSum = lSum - cardPoints[i];
            rSum = rSum + cardPoints[rIdx];
            rIdx = rIdx-1;
            maxSum=max(maxSum, lSum+rSum);
        }
        
        return maxSum;
       
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        int hash[26] = {0};
        int maxLen = INT_MIN, maxF=0;
        int l=k;
        while(j<s.length()){
            hash[s[j]-'A']++;
             maxF = max(maxF, hash[s[j] - 'A']);
            
            int changes = (j-i+1) - maxF;
            while(changes>k){
                hash[s[i]-'A']--;
                i++;
                changes = (j-i+1) - maxF;
            }
           
                maxLen=max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
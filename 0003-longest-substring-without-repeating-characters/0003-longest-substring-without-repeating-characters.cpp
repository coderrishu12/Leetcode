class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         Approach 2
        vector<int> hashVec(255,-1);
        
        int i=0, j=0;
        int len=0, maxLen=0;
        while(j<s.length()){
            if(hashVec[s[j]]!=-1){
                if(hashVec[s[j]]>=i){
                    i = hashVec[s[j]]+1;
                }
            }
            
            len=j-i+1;
            maxLen = max(maxLen, len);
            hashVec[s[j]] = j;
            j++;
        }
        return maxLen;
        
        
//         Approach 1 
//         unordered_map<int, int> mp;
//         int n = s.length();
//         int len = 0;
//         int maxi = 0;
//         int i=0,j=0;
//         while(j<n){
            
//             mp[s[j]-'a']++;
//             len++;
            
//             while(mp[s[j]-'a']>1){
//                 mp[s[i]-'a']--;
//                 i++;
//                 len--;
//             }
            
            
//             j++;
//             maxi = max(maxi,len);
//         }
//         return maxi;
    }
};
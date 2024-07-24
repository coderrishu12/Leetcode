class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int n = s.length();
        int len = 0;
        int maxi = 0;
        int i=0,j=0;
        while(j<n){
            
            mp[s[j]-'a']++;
            len++;
            
            while(mp[s[j]-'a']>1){
                mp[s[i]-'a']--;
                i++;
                len--;
            }
            
            
            j++;
            maxi = max(maxi,len);
        }
        return maxi;
    }
};
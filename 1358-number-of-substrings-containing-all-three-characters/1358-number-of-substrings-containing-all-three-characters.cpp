class Solution {
public:
    int subString(string &s, int k){
        int i=0, j=0, cnt=0;
        unordered_map<int, int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                    i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    
    
    int numberOfSubstrings(string s) {
//         Approach 3
        int k=3;
        int count = subString(s, k)-subString(s,k-1);
        return count;
        
        
//        Approach 2
        
        // int lastSeen[3]={-1, -1, -1}, cnt=0;
        // for(int i=0;i<s.length();i++){
        //     lastSeen[s[i]-'a']=i;
        //     if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
        //         cnt+= 1+ min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        //     }
        // }
        // return cnt;
        
//         Approach 1
        
//         int i=0, j=0, cnt=0;
//         int hash[3]={0};
//         while(j<s.length()){
//             if(s[j]=='a'){
//                 hash[0]++;
//             }else if(s[j]=='b'){
//                 hash[1]++;
//             }else if(s[j]=='c'){
//                 hash[2]++;
//             }
//             while(hash[0]>0 && hash[1]>0 && hash[2]>0){
//                 cnt+=(s.length()-j);
                
//                 if(s[i]=='a'){
//                     hash[0]--;
//                 }else if(s[i]=='b'){
//                     hash[1]--;
//                 }else if(s[i]=='c'){
//                     hash[2]--;
//                 }
//                     i++;
//             }
            
//             j++;
//         }
//         return cnt;
    }
};
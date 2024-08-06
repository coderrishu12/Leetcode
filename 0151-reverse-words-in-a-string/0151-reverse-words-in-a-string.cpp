class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        stringstream ss(s);
        string token = "";
        string result = "";
        while(ss>> token){
            result = token + " "+ result;
        }
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result.substr(0,n);
        
//         vector<string> vec;
        
//         int l=0;
        
//         for(int i=0;i<s.length();){
//             string str = "";
//             for(int j=i;j<s.length();j++){
//                 if(s[j]==' '){
//                     l=j;
//                     break;
//                 }
//                 str+=s[j];
//             }
//             vec.push_back(str);
//             i=l+1;
            
//         }
//         reverse(vec.begin(), vec.end());
//         string str="";
//         for(int i=0;i<vec.size();i++){
//             if(i==vec.size()-1){
//                 str+=vec[i];
//             }
//             else{
//                 str+=(vec[i]+" ");
//             }
//         }
//         return str;
    }
};
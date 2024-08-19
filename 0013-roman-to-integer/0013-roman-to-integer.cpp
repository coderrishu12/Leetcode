class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInteger = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.length();
        int sum=0;
        for(int i = 0;i<n;i++){
            int curr = romanToInteger[s[i]];
            if(i<n-1 && romanToInteger[s[i]]<romanToInteger[s[i+1]]){
                sum-=curr;
            }else{
                sum+=curr;
            }
        }
        return sum;
    }
};
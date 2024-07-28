class Solution {
public:
    bool isValid(string s) {
        string result;
        stack<char> st;
        
        for(auto i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else {
                if(!st.empty()){
                    auto str = st.top();
                    st.pop();
                    if(str == '(' && i == ')'){
                        result.push_back(str);
                        result.push_back(i);
                    }else if(str == '{' && i == '}'){
                        result.push_back(str);
                        result.push_back(i);
                    }else if(str == '[' && i == ']'){
                        result.push_back(str);
                        result.push_back(i);
                    }
                }
            }
        }
        return result.length() == s.length();
    }
};
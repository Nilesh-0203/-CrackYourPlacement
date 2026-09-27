class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string temp="";
        int open=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(temp.length());
            }
            else if(s[i]==')'){
                reverse(temp.begin()+st.top(),temp.end());
                st.pop();
            }
            else{
                temp+=s[i];
            }
        }
        return temp;
    }
};
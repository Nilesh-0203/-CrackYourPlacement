class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        string res="";
        int open=0,close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                ans+=s[i];
                open++;
            }
            else if(s[i]==')' && open>0){
                ans+=s[i];
                open--;
            }
            else if(s[i]==')' && open==0){
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]==')'){
                res+=ans[i];
                close++;
            }
            else if(ans[i]=='(' && close>0){
                res+=ans[i];
                close--;
            }
            else if(ans[i]=='(' && close==0){
                continue;
            }
            else{
                res+=ans[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
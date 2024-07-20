class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#' && st1.empty()) continue;
            else if(s[i]=='#' && !st1.empty()){
                st1.pop();
            }
            else{
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#' && st2.empty()) continue;
            else if(t[i]=='#' && !st2.empty()){
                st2.pop();
            }
            else{
                st2.push(t[i]);
            }
        }
        string ans1="",ans2="";
        while(!st1.empty()){
            ans1+=st1.top();
            st1.pop();
        }
        while(!st2.empty()){
            ans2+=st2.top();
            st2.pop();
        }
        return ans1==ans2;
    }
};
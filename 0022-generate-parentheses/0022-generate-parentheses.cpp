class Solution {
public:
    vector<string>v;
    void solve(int n,int open,int close,string ans){
        if(ans.length()==2*n){
            v.push_back(ans);
            return;
        }
        if(open<n){
            ans.push_back('(');
            solve(n,open+1,close,ans);
            ans.pop_back();
        }
        if(close<open){
            ans.push_back(')');
            solve(n,open,close+1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        string ans="";
        solve(n,open,close,ans);
        return v;
    }
};
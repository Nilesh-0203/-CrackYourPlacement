class Solution {
public:
    int t[101];
    int n;
    int solve(int i,string &s,vector<int>&dp){
        if(i==n){
            return 1; 
        }
        if(s[i]=='0'){
            return 0; //not possible to split
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int one=solve(i+1,s,dp); //take one character
        int two=0; // two charcter 
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1] <'7')){
             two+=solve(i+2,s,dp);
           }
        }
        return dp[i]=one+two;
    }
    int numDecodings(string s) {
        n=s.length();
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
};
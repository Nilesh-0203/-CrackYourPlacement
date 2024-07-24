class Solution {
public:
    int n;
    int mod=1e9+7;
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==s[j]){
            ans=2*solve(s,i+1,j-1,dp);
            int l=i+1,r=j-1;
            while(l<=r and s[l]!=s[i]) l++;
            while(l<=r and s[r]!=s[j]) r--;
            if(l < r) ans-=solve(s,l+1,r-1,dp);
            else if(l==r) ans++;
            else ans+=2;
        }
        else ans = solve(s,i+1,j,dp)+solve(s,i,j-1,dp)-solve(s,i+1,j-1,dp);
        return dp[i][j] = ans < 0 ? (ans+mod) % mod : ans % mod;
    }
    int countPalindromicSubsequences(string s) {
        n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};
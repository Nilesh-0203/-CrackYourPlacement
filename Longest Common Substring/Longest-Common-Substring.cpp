int m,n;
    int ans=0;
    int solve(string &s1,string& s2,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cnt=0;
        if(s1[i]==s2[j]){
            cnt=1+solve(s1,s2,i+1,j+1,dp);
            ans=max(ans,cnt);
        }
        int moveS1=solve(s1,s2,i+1,j,dp);
        int moveS2=solve(s1,s2,i,j+1,dp);
        return dp[i][j]=cnt;
    }
    int longestCommonSubstr (string S1, string S2, int M, int N)
    {
        // your code here
        m=M;n=N;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        solve(S1,S2,0,0,dp);
        return ans;
    }

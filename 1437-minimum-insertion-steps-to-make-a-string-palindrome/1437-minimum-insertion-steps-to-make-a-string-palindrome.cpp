class Solution {
public:
    int n;
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return solve(s,i+1,j-1,dp);
        }
        int insertAtBegin=solve(s,i+1,j,dp);
        int insertAtEnd=solve(s,i,j-1,dp);
        return dp[i][j]=1+min(insertAtBegin,insertAtEnd);
    }
    int minInsertions(string s) {
        n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};
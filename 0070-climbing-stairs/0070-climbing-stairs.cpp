class Solution {
public:
    int solve(int n,int idx,vector<int>&dp){
        if(idx==n){
            return 1;
        }
        if(idx>n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take_one=solve(n,idx+1,dp);
        int take_two=solve(n,idx+2,dp);
        return dp[idx]=take_one+take_two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,0,dp);
    }
};
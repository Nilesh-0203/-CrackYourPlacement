class Solution {
public:
    int n;
    int solve(vector<int>&coins,int idx,int amount,vector<vector<int>>&dp){
        if(idx>=n || amount<=0){
            return amount==0 ? 0 : INT_MAX-1;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int ans=-1;
        if(coins[idx]>amount){
            ans=solve(coins,idx+1,amount,dp);
        }
        else{
            int take=1+solve(coins,idx,amount-coins[idx],dp);
            int not_take=solve(coins,idx+1,amount,dp);
            ans=min(take,not_take);
        }
        return dp[idx][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int res=solve(coins,0,amount,dp);
        return res==INT_MAX-1 ? -1 :res;
    }
};
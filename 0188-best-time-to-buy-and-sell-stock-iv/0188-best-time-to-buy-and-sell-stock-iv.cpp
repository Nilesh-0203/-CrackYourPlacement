class Solution {
public:
    int n;
    int solve(vector<int>&prices,int idx,bool buy,int limit,vector<vector<vector<int>>>&dp){
        if(idx>=n){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[idx][buy][limit]!=-1){
            return dp[idx][buy][limit];
        }
        int profit=0;
        if(buy){
            int buy_karo=-prices[idx]+solve(prices,idx+1,!buy,limit,dp);
            int skip_karo=solve(prices,idx+1,buy,limit,dp);
            profit=max(buy_karo,skip_karo);
        }
        else{
            int sell_karo=prices[idx]+solve(prices,idx+1,!buy,limit-1,dp);
            int skip_karo=solve(prices,idx+1,buy,limit,dp);
            profit=max(sell_karo,skip_karo);
        }
        return dp[idx][buy][limit]=profit;
    }
    int solveTab(vector<int>&prices,int k){
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    int profit=0;
                    if(buy){
                        int buy_karo=-prices[idx]+dp[idx+1][!buy][limit];
                        int skip_karo=dp[idx+1][buy][limit];
                        profit=max(buy_karo,skip_karo);
                    }
                    else{
                        int sell_karo=prices[idx]+dp[idx+1][!buy][limit-1];
                        int skip_karo=dp[idx+1][buy][limit];
                        profit=max(sell_karo,skip_karo);
                    }
                    dp[idx][buy][limit]=profit;
                }
            }
        }
        return dp[0][true][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        return solveTab(prices,k);
    }
};
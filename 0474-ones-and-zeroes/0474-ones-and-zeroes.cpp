class Solution {
public:
    vector<int> count(string s){
        vector<int>temp(2,0);
        for(char ch:s){
            if(ch=='0'){
                temp[0]++;
            }
            else{
                temp[1]++;
            }
        }
        return temp;
    }
    int solve(vector<string>&strs,int m,int n,int idx,vector<vector<vector<int>>>&dp){
        if(idx>=strs.size() || m+n==0){
            return 0;
        }
        if(dp[m][n][idx]!=-1){
            return dp[m][n][idx];
        }
        vector<int>v=count(strs[idx]);
        int take=0;
        if(m>=v[0] && n>=v[1]){
            take=1+solve(strs,m-v[0],n-v[1],idx+1,dp);
        }
        int not_take=solve(strs,m,n,idx+1,dp);
        return dp[m][n][idx]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(len+1,-1)));
        return solve(strs,m,n,0,dp);
    }
};
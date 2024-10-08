class Solution {
public:
    int solveTab(int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j]=1;
                }
                else{
                    int down=dp[i+1][j];
                    int right=dp[i][j+1];
                    dp[i][j]=down+right;
                }
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        return solveTab(m,n);
    }
};
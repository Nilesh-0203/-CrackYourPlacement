class Solution {
public:
    int m,n;
    int solveTab(vector<vector<int>>& grid){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int right=INT_MAX,down=INT_MAX;
                    if(i+1<m){
                        down=grid[i][j]+dp[i+1][j];
                    }
                    if(j+1<n){
                        right=grid[i][j]+dp[i][j+1];
                    }
                    dp[i][j]=min(right,down);
                }
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        return solveTab(grid);
    }
};
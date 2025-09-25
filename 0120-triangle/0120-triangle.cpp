class Solution {
public:
    int m,n;
    int solveTab(vector<vector<int>>& triangle){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==m-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int down=triangle[i][j]+dp[i+1][j];
                    int diagonal=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(down,diagonal);
                }
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        n=m;
        return solveTab(triangle);
    }
};
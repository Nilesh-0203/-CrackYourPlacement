class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    bool valid(vector<vector<int>>&matrix,int new_i,int new_j,int i,int j){
        if(new_i<0 || new_j<0 || new_i>=m || new_j>=n || matrix[new_i][new_j]<=matrix[i][j]){
            return false;
        }
        return true;
    }
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int currMax=1;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(valid(matrix,new_i,new_j,i,j)){
                currMax=max(currMax,1+solve(matrix,new_i,new_j,dp));
            }
        }
        return dp[i][j]=currMax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi=0;
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,solve(matrix,i,j,dp));
            }
        }
        return maxi;
    }
};
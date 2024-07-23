int solve(int n,int x,int y,int z,int idx,vector<int>&dp){
        if(idx==n){
            return 0;
        }
        if(idx>n){
            return INT_MIN;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take_x=1+solve(n,x,y,z,idx+x,dp);
        int take_y=1+solve(n,x,y,z,idx+y,dp);
        int take_z=1+solve(n,x,y,z,idx+z,dp);
        
        return dp[idx]=max(take_x,max(take_y,take_z));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int ans=solve(n,x,y,z,0,dp);
        return ans<0 ? 0 :ans;
    }

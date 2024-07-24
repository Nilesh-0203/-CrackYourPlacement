class Solution {
public:
    int m,n;
    int ans=0;
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int cnt=0;
        if(nums1[i]==nums2[j]){
            cnt=1+solve(nums1,nums2,i+1,j+1,dp);
            ans=max(ans,cnt);
        }
        int moveone=solve(nums1,nums2,i+1,j,dp);
        int movetwo=solve(nums1,nums2,i,j+1,dp);
        return dp[i][j]=cnt;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        solve(nums1,nums2,0,0,dp);
        return ans;
    }
};
class Solution {
public:
   int n;
   int solve(vector<int>&nums,int idx,vector<int>&dp){
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int currVal=nums[idx];
    int currSum=nums[idx];
    int index=idx+1;
    while(index<n && nums[index]==currVal){
        currSum+=nums[idx];
        index++;
    }
    while(index<n && nums[index]==currVal+1){
        index++;
    }
    return dp[idx]=max(currSum+solve(nums,index,dp),solve(nums,idx+1,dp));
   }
    int deleteAndEarn(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n+1,-1);
        sort(nums.begin(),nums.end());
        return solve(nums,0,dp);
    }
};
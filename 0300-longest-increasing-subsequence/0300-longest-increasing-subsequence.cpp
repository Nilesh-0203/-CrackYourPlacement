class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(vector<int>&nums,int idx,int prev){
        if(idx>=n){
            return 0;
        }
        if(prev!=-1 && t[idx][prev]!=-1){
            return t[idx][prev];
        }
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+solve(nums,idx+1,idx);
        }
        int not_take=solve(nums,idx+1,prev);
        if(prev!=-1){
            t[idx][prev]=max(take,not_take);
        }
        return max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};
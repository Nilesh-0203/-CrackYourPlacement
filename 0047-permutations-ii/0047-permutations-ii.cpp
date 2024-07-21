class Solution {
public:
    int n;
    void solve(vector<int>&nums,int idx,vector<vector<int>>&result){
        if(idx==n){
            result.push_back(nums);
            return;
        }
        unordered_map<int,int>mp;
        for(int i=idx;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }
            else{
                mp[nums[i]]++;
                swap(nums[idx],nums[i]);
                solve(nums,idx+1,result);
                swap(nums[idx],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        solve(nums,0,result);
        sort(result.begin(),result.end());
        return result;
    }
};
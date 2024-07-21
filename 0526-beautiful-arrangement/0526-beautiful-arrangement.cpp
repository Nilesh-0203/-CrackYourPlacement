class Solution {
public:
    int count=0;
    void solve(vector<int>& nums,int idx){
        if(idx==nums.size()){
            count++;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            if(nums[idx]%(idx+1)==0 || (idx+1)%nums[idx]==0){
                solve(nums,idx+1);
            }
            swap(nums[idx],nums[i]);
        }
    }
    int countArrangement(int n) {
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        solve(nums,0);
        return count;
    }
};
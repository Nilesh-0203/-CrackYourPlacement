class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]+nums[i+1]>nums[i+2]){
                maxi=max(maxi,nums[i]+nums[i+1]+nums[i+2]);
            }
        }
        return maxi;
    }
};
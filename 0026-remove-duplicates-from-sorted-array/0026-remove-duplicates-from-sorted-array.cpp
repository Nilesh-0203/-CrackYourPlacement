class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]=INT_MAX;
                cnt++;
            }
        }
        sort(nums.begin(),nums.end());
        return n-cnt;
    }
};
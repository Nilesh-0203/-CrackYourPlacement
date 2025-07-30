class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxE=*max_element(nums.begin(),nums.end());
        int ans=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxE){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return max(ans,cnt);
    }
};
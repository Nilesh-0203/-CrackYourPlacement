class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=INT_MIN;
        int i=0,j=0;
        int zeroCount=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zeroCount++;
            }
            while(zeroCount>1){
                if(nums[i]==0){
                    zeroCount--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
};
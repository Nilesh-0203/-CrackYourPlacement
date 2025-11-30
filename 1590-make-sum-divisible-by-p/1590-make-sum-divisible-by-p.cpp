class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            sum=(sum+num)%p;
        }
        int target=sum%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int>mp;
        mp[0]=-1;
        int curr=0;
        int result=n;
        for(int i=0;i<n;i++){
            curr=(curr+nums[i])%p;
            int remain=(curr-target+p)%p;
            if(mp.find(remain)!=mp.end()){
                result=min(result,i-mp[remain]);
            }
            mp[curr]=i;
        }
        return result==n ? -1 :result;
    }
};
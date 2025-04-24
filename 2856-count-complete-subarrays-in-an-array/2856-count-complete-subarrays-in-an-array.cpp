class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int a:nums){
            st.insert(a);
        }
        int NoOfDistint=st.size();
        if(NoOfDistint==1){
            return (n*(n+1))/2;
        }
        int i=0,j=0;
        int count=0;
        map<int,int>mp;
        while(j<n && i<n){
            mp[nums[j]]++;
            if(mp.size()==NoOfDistint){
                count+=(n-j);
                while(i<j && mp.size()==NoOfDistint){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)mp.erase(nums[i]);
                    if(mp.size()==NoOfDistint)count+=(n-j);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};
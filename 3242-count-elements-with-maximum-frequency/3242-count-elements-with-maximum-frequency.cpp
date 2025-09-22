class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>v;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            v.push_back(i.second);
        }
        int maxi=*max_element(v.begin(),v.end());
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==maxi){
                count++;
            }
        }
        return count;
    }
};
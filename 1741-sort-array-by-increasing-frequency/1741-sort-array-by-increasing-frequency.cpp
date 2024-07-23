class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(begin(v),end(v),comp);
        vector<int>ans;
        int idx=0;
        while(idx<v.size()){
            pair<int,int>top=v[idx];
            int freq=top.second;
            while(freq--)
              ans.push_back(top.first);
            idx++;
        }
        return ans;
    }
};
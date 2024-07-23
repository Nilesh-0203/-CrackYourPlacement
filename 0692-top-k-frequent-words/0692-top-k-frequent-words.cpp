class Solution {
public:
    static bool comp(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string word:words){
            mp[word]++;
        }
        vector<pair<string,int>>temp(mp.begin(),mp.end());
        sort(begin(temp),end(temp),comp);

        vector<string>ans;
        int idx=0;
        while(idx<k){
            pair<string,int>top=temp[idx];
            ans.push_back(top.first);
            idx++;
        }
        return ans;
    }
};
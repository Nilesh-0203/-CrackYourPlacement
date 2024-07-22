class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:mp){
            pair<int,int>p={i.second,i.first};
            pq.push(p);
        }
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
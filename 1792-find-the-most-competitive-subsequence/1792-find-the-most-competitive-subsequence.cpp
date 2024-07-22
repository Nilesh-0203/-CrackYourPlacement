class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
         int rem=n-k;
        vector<int>v(k,0);
        for(auto a:nums){
            while(ans.size() && rem && ans.back()>a){
                ans.pop_back();
                rem--;
            }
            ans.push_back(a);
        }
        while(rem){
            ans.pop_back();
            rem--;
        }
        return ans;
    }
};
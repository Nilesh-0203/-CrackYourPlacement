class Solution {
public:
    vector<vector<int>>result;
    int n;
    void solve(vector<int>&candidates,int idx,int target,vector<int>&temp){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(idx>=n || target<0){
            return;
        }
        temp.push_back(candidates[idx]);
        solve(candidates,idx+1,target-candidates[idx],temp);
        temp.pop_back();
        while(idx<n-1 && candidates[idx]==candidates[idx+1]){
            idx++;
        }
        solve(candidates,idx+1,target,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,temp);
        return result;
    }
};
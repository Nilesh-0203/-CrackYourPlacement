class Solution {
public:
    vector<vector<int>> result;
    void solve(int n,int idx,int k,vector<int>&temp){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            solve(n,i+1,k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n,1,k,temp);
        return result;
    }
};
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       map<int,int>mp;
       vector<int>v;
       int m=matrix.size();
       int n=matrix[0].size();
       for(int i=0;i<m;i++){
            int ans=INT_MAX;
            for(int j=0;j<n;j++){
                ans=min(ans,matrix[i][j]);
            }
            mp[ans]++;
       }
       for(int i=0;i<n;i++){
            int ans=INT_MIN;
            for(int j=0;j<m;j++){
                ans=max(ans,matrix[j][i]);
            }
            if(mp.find(ans)!=mp.end()){
                v.push_back(ans);
            }
       }
       return v;
    }
};
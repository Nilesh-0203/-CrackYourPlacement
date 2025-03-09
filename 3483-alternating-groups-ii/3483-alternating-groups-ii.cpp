class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int j=0;
        int n=colors.size();
        int cnt=1;
        int ans=0;
        vector<int> v = colors;
        for(auto it : colors) v.push_back(it);
        for(int i=1;i<n+k-1;i++){
            if(v[i]!=v[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=k){
                ans++;
            }
        }
        return ans;
    }
};
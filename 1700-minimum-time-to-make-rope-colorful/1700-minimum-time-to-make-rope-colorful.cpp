class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=colors.size();
        int i=0,j=1;
        while(i<n && j<n){
            if(colors[i]!=colors[j]){
                i=j;
                j++;
            }
            else{
                ans+=min(neededTime[i],neededTime[j]);
                if(neededTime[i]<neededTime[j]){
                    i=j;
                }
                j++;
            }
        }
        return ans;
    }
};
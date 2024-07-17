class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0;
        int ans=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        int n=cardPoints.size()-1;
        ans=max(ans,leftSum);
        while(--k>=0){
            leftSum=leftSum-cardPoints[k]+cardPoints[n];
            ans=max(ans,leftSum);
            n--;
        }
        return ans;
    }
};
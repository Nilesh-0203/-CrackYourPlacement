class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(int person,int i,int M,vector<int>&piles){
        if(i>=n){
            return 0;
        }
        if(t[person][i][M]!=-1){
            return t[person][i][M];
        }
        int stones=0;
        int result=(person==1) ? -1:INT_MAX;
        for(int x=1;x<=min(2*M,n-i);x++){
            stones+=piles[i+x-1];
            if(person==1){
                result=max(result,stones+solve(0,i+x,max(M,x),piles));
            }
            else{
                result=min(result,solve(1,i+x,max(M,x),piles));
            }
        }
        return t[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solve(1,0,1,piles);
    }
};
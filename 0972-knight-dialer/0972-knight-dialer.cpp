class Solution {
public:
    int mod=1e9+7;
    int t[5001][10];
    vector<vector<int>> adj{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{4,2}};
    int solve(int n,int cell){
        if(n==0){
            return 1;
        }
        if(t[n][cell]!=-1){
            return t[n][cell];
        }
        int ans=0;
        for(int &next:adj[cell]){
            ans=(ans+solve(n-1,next))%mod;
        }
        return t[n][cell]=ans;
    }
    int knightDialer(int n) {
       int res=0;
       memset(t,-1,sizeof(t));
       for(int i=0;i<=9;i++){
        res=(res+solve(n-1,i))%mod;
       }  
       return res;
    }
};
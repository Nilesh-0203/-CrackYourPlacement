class Solution {
public:
    int no_ob_count;
    int m,n;
    int ans=0;
    vector<vector<int>>directios{{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<int>>& grid,int count,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(count==no_ob_count){
                ans++;
            }
            return;
        }
        grid[i][j]=-1;
        for(auto dir:directios){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            solve(grid,count+1,new_i,new_j);
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        no_ob_count=0;
        int x=0,y=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    no_ob_count++;
                }
                if(grid[i][j]==1){
                    x=i;y=j;
                }
            }
        }
        no_ob_count+=1;
        solve(grid,0,x,y);
        return ans;
    }
};
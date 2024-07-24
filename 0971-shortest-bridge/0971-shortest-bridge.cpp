class Solution {
public:
    vector<pair<int,int>> first,second;
    int m,n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void solve(int i,int j, int no, vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1){
            return;
        }
        grid[i][j]=no;
        if(no==2){
            first.push_back({i,j});
        }
        else{
            second.push_back({i,j});
        }
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            solve(new_i,new_j,no,grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int count=2;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                  solve(i,j,count,grid);
                  count++;
                }
            }
        }
        int ans=1000000;
        for(int i=0;i<first.size();i++)
            for(int j=0;j<second.size();j++)
                ans=min(abs(first[i].first-second[j].first)+abs(first[i].second-second[j].second)-1,ans);
        return ans;
    }
};
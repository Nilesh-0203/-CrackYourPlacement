    int m,n;
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            dfs(grid,new_i,new_j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }

class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int n;
    int solve(vector<vector<int>>&grid,int i,int j,int &color){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || grid[i][j]==color){
            return 0;
        }
        grid[i][j]=color;
        int currMax=1;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            currMax+=solve(grid,new_i,new_j,color);
        }
        return currMax;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int color=2;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=solve(grid,i,j,color);
                    mp[color]=count;
                    color++;
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    if(i-1>=0 && grid[i-1][j]!=0){
                        st.insert(grid[i-1][j]);
                    }
                    if(i+1<n && grid[i+1][j]!=0){
                        st.insert(grid[i+1][j]);
                    }
                    if(j-1>=0 && grid[i][j-1]!=0){
                        st.insert(grid[i][j-1]);
                    }
                    if(j+1<n && grid[i][j+1]!=0){
                        st.insert(grid[i][j+1]);
                    }
                    int sum=1;
                    for(auto i:st){
                        sum+=mp[i];
                    }
                    maxi=max(maxi,sum);
                }
            }
        }
        if(maxi==0){
            return n*n;
        }
        return maxi;
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
                    if(matrix[i][via]==INT_MAX || matrix[via][j]==INT_MAX){
                        continue;
                    }
    	           matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
    	        }
    	    }
	    }
        int cntCity=n;
        int cityNo=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(matrix[city][adjCity]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cntCity){
                cntCity=cnt;
                cityNo=city;
            }
        }
        return cityNo;
    }
};
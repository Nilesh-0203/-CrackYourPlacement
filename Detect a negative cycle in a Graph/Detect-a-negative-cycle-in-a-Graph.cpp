int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0;i<n-1;i++){
	        for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            
	            if(dist[u]!=INT_MAX && (dist[u]+wt<dist[v])){
	                dist[v]=dist[u]+wt;
	            }
	        }
	    }
	    for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            
	            if(dist[u]!=INT_MAX && (dist[u]+wt<dist[v])){
	                return 1;
	       }
	   }
	   return 0;
	}

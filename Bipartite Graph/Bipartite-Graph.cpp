bool solve(int node,vector<int>&color,vector<int>adj[]){
        color[node]=0;
	    queue<int>q;
	    q.push(node);
	    
	    while(!q.empty()){
	        int n=q.front();
	        q.pop();
	        
	        for(auto it:adj[n]){
	            if(color[it]==-1){
	                color[it]=!color[n];
	                q.push(it);
	            }
	            else if(color[it]==color[n]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	     vector<int>color(V,-1);
	     for(int i=0;i<V;i++){
	         if(color[i]==-1){
	             if(solve(i,color,adj)==false){
	                 return false;
	             }
	         }
	     }
	     return true;
	}

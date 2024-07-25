vector<int>parent;
	vector<int>rank;
	int find(int x){
	    if(x==parent[x]){
	        return x;
	    }
	    return parent[x]=find(parent[x]);
	}
	void Union(int x,int y){
	    int x_parent=find(x);
	    int y_parent=find(y);
	    
	    if(x_parent==y_parent){
	        return;
	    }
	    if(rank[x_parent]>rank[y_parent]){
	        parent[y_parent]=x_parent;
	    }
	    else if(rank[x_parent]<rank[y_parent]){
	        parent[x_parent]=y_parent;
	    }
	    else{
	        parent[x_parent]=y_parent;
	        rank[y_parent]++;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        for(int i = 0; i<V; i++)
            parent[i] = i;
        
        vector<pair<int, pair<int, int>>> edges;
        for(int u=0; u<V; u++){
            for(int j=0; j<adj[u].size(); j++){
                
                int v = adj[u][j][0];
                int w = adj[u][j][1];
                
                edges.push_back({w, {u, v}});
                
            }
        }
        sort(edges.begin(),edges.end());
        int minWeight=0;
        for(int i=0;i<edges.size();i++){
            int u=find(edges[i].second.first);
            int v=find(edges[i].second.second);
            int wt=edges[i].first;
            
            if(u!=v){
                minWeight+=wt;
                Union(u,v);
            }
        }
        return minWeight;
    }

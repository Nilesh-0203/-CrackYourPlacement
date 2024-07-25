void dfs(int node,vector<int> adj[],vector<bool>&visited,stack<int>&s){
    visited[node]=true;
    for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited, s);
            }
        }
        s.push(node);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   vector<int>ans;
        vector<bool>visited(V);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    	}

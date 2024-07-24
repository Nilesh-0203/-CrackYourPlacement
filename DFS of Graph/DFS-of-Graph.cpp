void dfs(vector<int>adj[],unordered_map<int,bool>&visited,int node,vector<int>&ans){
        visited[node]=true;
        ans.push_back(node);
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(adj,visited,neighbor,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
               dfs(adj,visited,i,ans);
            }
        }
        return ans;
    }

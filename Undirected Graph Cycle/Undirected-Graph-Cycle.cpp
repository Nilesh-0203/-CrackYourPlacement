bool isCycledfs(vector<int> adj[],unordered_map<int,bool>&visited,int node,int parent){
        visited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                bool cycle=isCycledfs(adj,visited,neighbor,node);
                if(cycle){
                    return true;
                }
            }
            else if(neighbor!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle=isCycledfs(adj,visited,i,-1);
                if(cycle){
                    return true;
                }
            }
        }
        return false;
    }

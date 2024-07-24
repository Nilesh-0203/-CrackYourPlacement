vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        visited[0]=true;
        queue<int>q;
        vector<int>ans;
        q.push(0);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbor:adj[front]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
        return ans;
    }

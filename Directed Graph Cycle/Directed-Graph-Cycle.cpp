bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int count=0;
        vector<int>inorder(V);
        for(auto i=0;i<V;i++){
            for(auto j:adj[i]){
                inorder[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(auto neighbor:adj[front]){
                inorder[neighbor]--;
                if(inorder[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        return count!=V;
    }

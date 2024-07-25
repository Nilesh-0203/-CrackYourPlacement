void dfs(int node,   unordered_map<int,bool> &vis, stack<int>&st,vector<vector<int>>& adj){
        vis[node] = true;
        for(auto e:adj[node]){
            if(!vis[e]){
                dfs(e,vis, st, adj);
            }
        }
        st.push(node);
    }
    void revofdfs(int node, unordered_map<int,bool> &vis, unordered_map<int,list<int>> & adj){
        vis[node] = true;
        for(auto e:adj[node]){
            if(!vis[e]){
                revofdfs(e, vis, adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //push in stack each node using dfs
     stack<int>st;
     unordered_map<int,bool>vis;
     for(int i=0; i<V; i++){
          if(!vis[i]){
              dfs(i, vis, st, adj);
          }
     }
     //transpose the graph because element in stack in reverse order
     unordered_map<int,list<int>>transpose;
      for(int i=0; i<V; i++){
          vis[i] = false; 
          for(auto e:adj[i]){
            transpose[e].push_back(i);
      }
     }
     //now count all strong connected components using dfs
     int count =0;
     while(!st.empty()){
         int top = st.top();
         st.pop();
         if(!vis[top]){
            revofdfs(top, vis, transpose);
            count++;
         }
     }
     return count;
    }

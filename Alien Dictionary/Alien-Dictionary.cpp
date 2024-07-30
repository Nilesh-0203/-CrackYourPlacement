void dfs(int node,unordered_map<int,list<int>>&adj,vector<bool>&visited,stack<int>&s){
        visited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited, s);
            }
        }
        s.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<N-1;i++){
            int j=0;
            int n=dict[i].size();
            int m=dict[i+1].size();
            int len=min(n,m);
            while(j<len && dict[i][j]==dict[i+1][j]){
                j++;
            }
            if(j!=len){
             adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');   
            }
        }
        string ans="";
        vector<bool>visited(K,0);
        stack<int>s;
        for(int i=0;i<K;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        while(!s.empty()){
            int x=s.top();
            ans+=(char)(x+'a');
            s.pop();
        }
        return ans;
    }

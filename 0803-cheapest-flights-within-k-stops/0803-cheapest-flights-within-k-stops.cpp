class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        int stops=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty() && stops<=k){
            int size=q.size();
            while(size--){
                pair<int,int>node=q.front();
                q.pop();

                for(auto neighbor:adj[node.first]){
                    if(neighbor.second+node.second >=dist[neighbor.first]){
                        continue;
                    }
                    dist[neighbor.first]=neighbor.second+node.second;
                    q.push({neighbor.first,dist[neighbor.first]});
                }
            }
            stops++;
        }
        return dist[dst]==INT_MAX ? -1:dist[dst];
    }
};
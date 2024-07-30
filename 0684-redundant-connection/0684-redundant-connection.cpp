class Solution {
public:
    bool dfs(int node, int parent, unordered_map<int,list<int>>&adj, vector<bool>&vis) {
        vis[node] = true;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, node, adj, vis))
                    return true;
            } else if (neighbor != parent)
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,list<int>>adj;
        for (int i = 0; i < n; i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n, false);
            if (dfs(edges[i][0], -1, adj, vis)) {
                return edges[i];
            }
        }
        return {};
    }
};
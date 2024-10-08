class Solution {
public:
    void dfs(string src,string dist,unordered_map<string,vector<pair<string,double>>>&adj,unordered_set<string>&visited,
    double product,double &ans){
        if(visited.find(src)!=visited.end()){
            return;
        }
        visited.insert(src);
        if(src==dist){
            ans=product;
            return;
        }
        for(auto &i: adj[src]){
            string v=i.first;
            double val=i.second;

            dfs(v,dist,adj,visited,product*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        vector<double>v;
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dist=queries[i][1];

            double ans=-1.0;
            double product=1.0;
            if(adj.find(src)!=adj.end()){
                unordered_set<string>visited;
                dfs(src,dist,adj,visited,product,ans);
            }
            v.push_back(ans);
        }
        return v;
    }
};
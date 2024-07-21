class Solution {
public:
   
    vector<int> topoSortBFS(vector<vector<int>>&edges,int v){
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(v+1);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        queue<int>q;
        int count=0;
        for(int i=1;i<=v;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbor:adj[front]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                    count++;
                }
            }
        }
        if(count!=v){
            return {};
        }
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>v1=topoSortBFS(rowConditions,k);
        vector<int>v2=topoSortBFS(colConditions,k);
        for(int i:v1){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i:v2){
            cout<<i<<" ";
        }
        cout<<endl;
        if(v1.empty() || v2.empty()){
            return {};
        }
        vector<vector<int>>mat(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(v1[i]==v2[j]){
                    mat[i][j]=v1[i];
                }
            }
        }
        return mat;
    }
};
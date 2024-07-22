class Solution {
public:
    typedef pair<int,vector<int>>p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int t=x*x+y*y;
            pq.push({t,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        for(char ch:word){
            v[ch-'a']++;
        }
        priority_queue<int>pq;
        for(auto i:v){
            if(i>0){
                pq.push(i);
            }
        }
        int mini=0;
        int cnt=1;
        int mul=1;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            mul=cnt%8==0 ? cnt/8 : (cnt/8)+1;
            mini=mini+(top*mul);
            cnt++;
        }
        return mini;
    }
};
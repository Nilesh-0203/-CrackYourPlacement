class Solution {
public:
    string reorganizeString(string s) {
        vector<int>mp(26,0);
        int n=s.length();
        for(char ch:s){
            mp[ch-'a']++;
            if(mp[ch-'a']>(n+1)/2){
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        string result="";
        for(char ch='a';ch<='z';ch++){
            if(mp[ch-'a']>0){
                pq.push({mp[ch-'a'],ch});
            }
        }
        while(pq.size()>1){
            auto p1=pq.top();pq.pop();
            auto p2=pq.top();pq.pop();

            result.push_back(p1.second);p1.first--;
            result.push_back(p2.second);p2.first--;

            if(p1.first>0){
                pq.push({p1.first,p1.second});
            }
            if(p2.first>0){
                pq.push({p2.first,p2.second});
            }
        }
        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};
class Solution {
public:
    bool pali(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        int n=words.size();
        if(n<2){
            return ans;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            mp[temp]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=words[i].size();j++){
                string prefix=words[i].substr(0,j);
                string suffix=words[i].substr(j);
                if(mp.count(prefix) && pali(suffix) && mp[prefix]!=i){
                    ans.push_back({i,mp[prefix]});
                }
                if(!prefix.empty() && mp.count(suffix) && pali(prefix) && mp[suffix]!=i){
                    ans.push_back({mp[suffix],i});
                }
            }
        }
        return ans;
    }
};
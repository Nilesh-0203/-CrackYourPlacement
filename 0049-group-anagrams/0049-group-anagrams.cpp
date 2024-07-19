class Solution {
public:
    string solve(string word){
        vector<int>v(26,0);
        for(int i=0;i<word.length();i++){
            v[word[i]-'a']++;
        }
        string temp="";
        for(int i=0;i<26;i++){
            int freq=v[i];
            temp+=string(freq,i+'a');
        }
        return temp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            string newWord=solve(word);
            mp[newWord].push_back(word);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
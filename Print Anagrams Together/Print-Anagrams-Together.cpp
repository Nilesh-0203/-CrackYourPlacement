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
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<string_list.size();i++){
            string word=string_list[i];
            string newWord=solve(word);
            mp[newWord].push_back(word);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }

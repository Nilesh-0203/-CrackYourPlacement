class Solution {
public:
    string reverseWords(string s) {
        istringstream k(s);
        string word;
        vector<string>v;
        while(k>>word){
            v.push_back(word);
        }
        string res="";
        for(int i=v.size()-1;i>=0;i--){
            res+=v[i];
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};
class Solution {
public:
    void solve(vector<string>&result,string curr,int n){
        if(curr.length()==n){
            result.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(curr.length()>0 && curr.back()==ch){
                continue;
            }
            curr.push_back(ch);
            solve(result,curr,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr="";
        vector<string>result;
        solve(result,curr,n);
        int s=result.size();
        return s<k ? "" : result[k-1];
    }
};
class Solution {
public:
    vector<vector<string>>result;
    int n;
    bool isPalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int idx,vector<string>&curr){
        if(idx==n){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<string>curr;
        solve(s,0,curr);
        return result;
    }
};
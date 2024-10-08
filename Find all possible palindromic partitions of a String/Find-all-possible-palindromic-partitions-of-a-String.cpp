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
    void solve(string &S,int idx,vector<string>&temp){
        if(idx==n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(S,idx,i)){
                temp.push_back(S.substr(idx,i-idx+1));
                solve(S,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        n=S.length();
        vector<string>temp;
        solve(S,0,temp);
        return result;
    }

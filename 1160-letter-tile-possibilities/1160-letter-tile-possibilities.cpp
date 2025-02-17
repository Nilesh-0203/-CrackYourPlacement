class Solution {
public:
    int count;
    void solve(vector<int>&v){
        count++;
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                v[i]--;
                solve(v);
                v[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        count=0;
        vector<int>v(26,0);
        for(char ch:tiles){
            v[ch-'A']++;
        }
        solve(v);
        return count-1;
    }
};
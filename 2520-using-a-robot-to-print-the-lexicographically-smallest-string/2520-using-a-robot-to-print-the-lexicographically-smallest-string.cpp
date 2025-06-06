class Solution {
public:
    string robotWithString(string s) {
        int n=s.length();

        vector<char>minCharRight(n);
        minCharRight[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            minCharRight[i]=min(s[i],minCharRight[i+1]);
        }

        string t="";
        string paper="";

        int i=0;
        while(i<n){
            t.push_back(s[i]);

            char minChar=(i+1 < n)? minCharRight[i+1] : s[i];

            while(!t.empty() && t.back() <=minChar){
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;
    }
};
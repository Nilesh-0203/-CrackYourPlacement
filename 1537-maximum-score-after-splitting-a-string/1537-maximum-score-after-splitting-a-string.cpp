class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int zero=0,one=0,score=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
            score=max(score,zero-one);
        }
        if(s[n-1]=='1'){
            one++;
        }
        return score+one;
    }
};
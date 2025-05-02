class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        string ans=dominoes;
        vector<int>leftClosetR(n);
        int k=-1;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                k=i;
            }
            if(dominoes[i]=='L'){
                k=-1;
            }
            leftClosetR[i]=k;
        }
        int d=-1;
        vector<int>RightClosetL(n);
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                d=i;
            }
            if(dominoes[i]=='R'){
                d=-1;
            }
            RightClosetL[i]=d;
        }
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                if(leftClosetR[i]==-1 && RightClosetL[i]==-1)continue;
                else if(leftClosetR[i]==-1 && RightClosetL[i]!=-1)ans[i]='L';
                else if(leftClosetR[i]!=-1 && RightClosetL[i]==-1)ans[i]='R';
                else{
                    int distLeftR=abs(i-leftClosetR[i]);
                    int distRightL=abs(i-RightClosetL[i]);
                    if(distLeftR==distRightL){
                        continue;
                    }
                    else if(distLeftR>distRightL){
                        ans[i]='L';
                    }
                    else{
                        ans[i]='R';
                    }
                }
            }
        }
        return ans;
    }
};
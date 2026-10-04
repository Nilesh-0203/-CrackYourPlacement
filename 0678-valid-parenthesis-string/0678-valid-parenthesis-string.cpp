class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        stack<int>openSt;
        stack<int>asterikSt;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openSt.push(i);
            }
            else if(s[i]=='*'){
                asterikSt.push(i);
            }
            else{
                if(!openSt.empty()){
                    openSt.pop();
                }
                else if(!asterikSt.empty()){
                    asterikSt.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!openSt.empty() && !asterikSt.empty()){
            if(openSt.top() > asterikSt.top()){
                return false;
            }
            openSt.pop();
            asterikSt.pop();
        }
        return openSt.empty();
    }
};
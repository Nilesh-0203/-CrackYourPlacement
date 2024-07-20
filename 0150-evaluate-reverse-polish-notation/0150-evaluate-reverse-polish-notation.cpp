class Solution {
public:
    int operate(int a,int b,string op){
        if(op=="+"){
            return a+b;
        }
        if(op=="-"){
            return a-b;
        }
        if(op=="*"){
            return a*b;
        }
        if(op=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string token:tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int ans=operate(a,b,token);
                st.push(ans);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
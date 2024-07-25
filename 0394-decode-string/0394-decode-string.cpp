class Solution {
public:
    string decodeString(string s) {
        stack<int>No;
        stack<string>st;
        string result="";
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10 + (c-'0'); // if two come ex 14,22
            }
            else if(isalpha(c)){
                result+=c;
            }
            else if(c=='['){
                st.push(result);
                No.push(num);
                result="";
                num=0;
            }
            else if(c==']'){
                int n=No.top();
                No.pop();
                string temp=st.top();
                st.pop();
                for(int i=0;i<n;i++){
                    temp+=result;
                }
                result=temp;
            }
        }
        return result;
    }
};
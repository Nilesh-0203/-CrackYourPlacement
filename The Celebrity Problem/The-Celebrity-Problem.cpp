int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(M[a][b]==1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int candi=st.top();
        for(int i=0;i<n;i++){
            if(M[candi][i]==1){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(M[i][candi]==0 && i!=candi){
                return -1;
            }
        }
        return candi;
    }

void solve(Node* root, vector<int>&in ,  vector<int>&leaf )
    {
        if(root==0)
        return ;
        if(root->left==0 && root->right==0)
        leaf.push_back(root->data);
        solve(root->left, in, leaf);
        in.push_back(root->data);
        solve(root->right, in , leaf);
        
    }
    bool isDeadEnd(Node *root)
    { 
        vector<int>in;
        vector<int>leaf;
        solve(root,in, leaf);
        for(int i =0;i< leaf.size(); i++)
        {  int c=0, d=0;
            for(int j=0;j< in.size(); j++)
            {
                if(leaf[i]==1&& leaf[i]+1==in[j] )
                return true ;
                if(leaf[i]-1==in[j])
                {
                    c=1;
                }
                if(leaf[i]+1==in[j])
                d=1;
                if(c==1 && d==1)
                return true;
                
                
            }
        }
        return false;
    }

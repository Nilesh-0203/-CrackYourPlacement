int ans=0;
    void inorder(Node* root,int l,int h){
        if(root==NULL){
            return ;
        }
        inorder(root->left,l,h);
        if(root->data >=l && root->data <=h){
            ans++;
        }
        inorder(root->right,l,h);

    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here 
        if(root->data < l){
            inorder(root->right,l,h);
        }
        else if(root->data > h){
            inorder(root->left,l,h);
        }
        else{
            inorder(root,l,h);
        }
        return ans;
    }

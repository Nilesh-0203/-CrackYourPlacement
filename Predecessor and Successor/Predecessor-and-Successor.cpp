void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(!root) return;
        if(key < root -> key)
        {
            suc = root;
            findPreSuc(root -> left, pre, suc, key);
        }
        else if(key > root -> key)
        {
            pre = root;
            findPreSuc(root -> right, pre, suc, key);
        }
        else
        {
            findPreSuc(root -> right, pre, suc, key);
            findPreSuc(root -> left, pre, suc, key);
        }
    }

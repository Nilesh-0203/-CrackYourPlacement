void inorder(Node* root,vector<int>&v){
        if(root==NULL){
            return ;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        vector<int>v;
        inorder(root,v);
        if(v.size()==0){
            return NULL;
        }
        Node* head=new Node(v[0]);
        Node* tail=head;
        for(int i=1;i<v.size();i++){
            Node* newNode=new Node(v[i]);
            tail->right=newNode;
            newNode->left=tail;
            tail=newNode;
        }
        return head;
    }

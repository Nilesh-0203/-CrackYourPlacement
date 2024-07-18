    int n;
    void createMap(vector<int>&inorder,map<int,vector<int>>&mp){
        for(int i=0;i<n;i++){
            mp[inorder[i]].push_back(i);
        }
        for(auto &it:mp){
            reverse(it.second.begin(),it.second.end());
        }
    }
    Node* solve(vector<int>& inorder,vector<int>&preorder,
    int &index,int inorderStart,int inorderEnd,map<int,vector<int>>&mp){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=preorder[index++];
        
        Node* root=newNode(element);
        int position=mp[element].back();
        mp[element].pop_back();
        root->left=solve(inorder,preorder,index,inorderStart,position-1,mp);
        root->right=solve(inorder,preorder,index,position+1,inorderEnd,mp);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            temp[i]=pre[i];
        }
        vector<int>preorder=temp;
        sort(temp.begin(),temp.end());
        vector<int>inorder=temp;
        int preOrderIndex=0;
        n=inorder.size();
        map<int,vector<int>>mp;
        createMap(inorder,mp);
        Node* ans=solve(inorder,preorder,preOrderIndex,0,n-1,mp);
        return ans;
    }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL){
            parent[root->left]=root;
        }
        inorder(root->left,parent);
        if(root->right!=NULL){
            parent[root->right]=root;
        }
        inorder(root->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        inorder(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        int level=0;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(!q.empty() && level<k){
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                visited[front->left]=true;
                q.push(front->left);
            }
            if(front->right && !visited[front->right]){
                visited[front->right]=true;
                q.push(front->right);
            }
            if(parent[front] && !visited[parent[front]]){
                visited[parent[front]]=true;
                q.push(parent[front]);
            }
            }
            level++;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
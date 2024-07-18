/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder,int preStart,int preEnd,vector<int>&postorder,int postStart,int postEnd){
        if(preStart>preEnd){
            return NULL;
        }
        int element=preorder[preStart];
        TreeNode* root=new TreeNode(element);
        if(preStart==preEnd){
            return root;
        }
        int left_root=preorder[preStart+1];
        int i=postStart;
        while(i<=postEnd){
            if(postorder[i]==left_root){
                break;
            }
            i++;
        }
        int j=i-postStart+1;
        root->left=solve(preorder,preStart+1,preStart+j,postorder,postStart,i);
        root->right=solve(preorder,preStart+j+1,preEnd,postorder,i+1,postEnd-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return solve(preorder,0,n-1,postorder,0,n-1);
        return NULL;
    }
};
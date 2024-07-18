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
    pair<bool,int> isBalancedFast(TreeNode* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>leftNode=isBalancedFast(root->left);
        pair<bool,int>rightNode=isBalancedFast(root->right);

        pair<bool,int>ans;
        bool diff=abs(leftNode.second-rightNode.second)<=1;
        ans.second=max(leftNode.second,rightNode.second)+1;
        if(leftNode.first && rightNode.first && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};
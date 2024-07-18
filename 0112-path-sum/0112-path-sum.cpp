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
    bool solve(TreeNode* root,int sum,int target){
        if(root==NULL){
            return false;
        }
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL && sum==target){
            return true;
        }
        bool leftAns=solve(root->left,sum,target);
        bool rightAns=solve(root->right,sum,target);
        sum=sum-root->val;
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};
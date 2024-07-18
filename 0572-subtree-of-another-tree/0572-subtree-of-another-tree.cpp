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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool cond=p->val == q->val;

        if(left && right && cond){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        if(root==NULL && subRoot!=NULL){
            return false;
        }
        if(isSameTree(root,subRoot)){
            return true;
        }
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};
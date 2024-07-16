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
    TreeNode* lowestCommonAncestor(TreeNode* root,int p, int q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p || root->val==q){
            return root;
        }
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);

        if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        return NULL;
    }
    bool dfs(TreeNode* root,int target,string& temp){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true;
        }
        temp.push_back('L');
        if(dfs(root->left,target,temp)==true){
            return true;
        }
        temp.pop_back();

        temp.push_back('R');
        if(dfs(root->right,target,temp)==true){
            return true;
        }
        temp.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCANode=lowestCommonAncestor(root,startValue,destValue);
        string lcaToSec="";
        string lcaToDec="";
        dfs(LCANode,startValue,lcaToSec);
        dfs(LCANode,destValue,lcaToDec);

        for(int i=0;i<lcaToSec.length();i++){
            lcaToSec[i]='U';
        }
        string ans=lcaToSec+lcaToDec;
        return ans;
    }
};
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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll maxWidth=0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(!q.empty()){
            ll n=q.size();
            ll l=q.front().second;
            ll r=q.back().second;
            maxWidth=max(maxWidth,r-l+1);
            for(ll i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                ll index=q.front().second;
                q.pop();

                if(curr->left){
                    q.push({curr->left,2*index+1});
                }
                if(curr->right){
                    q.push({curr->right,2*index+2});
                }
            }
        }
        return maxWidth;
    }
};
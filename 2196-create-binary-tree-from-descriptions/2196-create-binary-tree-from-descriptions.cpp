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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>mp;
        unordered_set<int>st;
        for(vector<int>& it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];

            st.insert(child);
            if(mp.find(child)==mp.end()){
                TreeNode* childNode=new TreeNode(child);
                mp[child]=childNode;
            }
            if(mp.find(parent)==mp.end()){
                TreeNode* ParentNode=new TreeNode(parent);
                mp[parent]=ParentNode;
            }
            if(isleft==1){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
        }
        for(auto it:descriptions){
            if(st.find(it[0])==st.end()){
                return mp[it[0]];
            }
        }
        return NULL;
    }
};
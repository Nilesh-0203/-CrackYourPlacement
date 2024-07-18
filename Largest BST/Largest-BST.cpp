class NodeV{
    public :
        int minN , maxN, maxS ;
        
        NodeV(int minN, int maxN, int maxS)
        {
            this->minN = minN ;
            this->maxN = maxN ;
            this->maxS = maxS ;
        }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
      NodeV lBST(Node* root) 
    {
        if (!root) return NodeV(INT_MAX, INT_MIN, 0);

        auto l = lBST(root->left);
        auto r = lBST(root->right);

        if (l.maxN < root->data && root->data < r.minN) {
            return NodeV(min(root->data, l.minN), max(root->data, r.maxN), l.maxS + r.maxS + 1);
        }
        return NodeV(INT_MIN, INT_MAX, max(l.maxS, r.maxS));
    }

    int largestBst(Node* root) {
        return lBST(root).maxS;
    }
};

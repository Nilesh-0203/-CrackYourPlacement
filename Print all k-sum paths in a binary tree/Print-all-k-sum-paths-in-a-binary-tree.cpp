void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
void printKPathUtil(Node* root, vector<int>& path, int k)
{
    // empty node
    if (!root)
        return;
 
    path.push_back(root->data);
 
    printKPathUtil(root->left, path, k);
 
    printKPathUtil(root->right, path, k);
 
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--) {
        f += path[j];
 
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
 
    path.pop_back();
}
 
void printKPath(Node* root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

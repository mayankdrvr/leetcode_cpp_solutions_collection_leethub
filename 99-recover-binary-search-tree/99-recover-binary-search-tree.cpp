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

    vector<TreeNode*> tree;
 
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root);
        inOrder(root->right);
    }

    
    void recoverTree(TreeNode* root) {
     inOrder(root);
            int i, j;
        int n = tree.size();
    for (i = 0; i < n-1; i++)    
    for (j = 0; j < n-i-1; j++)
        if (tree[j]->val > tree[j+1]->val)
            swap(tree[j]->val, tree[j+1]->val);

    }
};
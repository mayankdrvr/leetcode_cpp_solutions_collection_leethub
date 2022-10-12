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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        //Storing the root->right as it will be updated on after return from root->left
		TreeNode* temp = root->right;
        //Now swap the left children and now ake left child as right
        root->right = invertTree(root->left);
		//make right child as left
        root->left = invertTree(temp);
        return root;
    }
};
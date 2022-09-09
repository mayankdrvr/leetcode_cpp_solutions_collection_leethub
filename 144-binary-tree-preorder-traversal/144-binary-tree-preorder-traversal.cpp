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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *currNode;
        while (s.size()) {
            currNode = s.top();
            s.pop();
            res.push_back(currNode->val);
            if (currNode->right) s.push(currNode->right);
            if (currNode->left) s.push(currNode->left);
        }
        return res;
    }
};
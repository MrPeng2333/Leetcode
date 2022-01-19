/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root -> val == key) {
            TreeNode* node = root -> left;
            if (!node) return root -> right;
            while (node -> right) {
                node = node -> right;
            }
            TreeNode* newNode = new TreeNode(node -> val);
            newNode -> left = deleteNode(root -> left, node -> val);
            newNode -> right = root -> right;
            delete root;
            return newNode;     
        }
        if (key < root -> val)
            root -> left = deleteNode(root -> left, key);
        else
            root -> right = deleteNode(root -> right, key);
        return root;
    }
};
// @lc code=end


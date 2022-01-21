/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode* pre = nullptr;
    bool helper(TreeNode* root) {
        if (!root) return true;
        bool left = helper(root -> left);
        if (pre && pre -> val >= root -> val) return false;
        pre = root;
        bool right = helper(root -> right);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};
// @lc code=end


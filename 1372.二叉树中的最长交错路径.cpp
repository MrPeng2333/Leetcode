/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    
    void helper(TreeNode* root, int leftOrRight, int len, int &ret) {
        if (!root) {
            ret = max(ret, len - 2);
            return;
        }
        leftOrRight == 1 ? helper(root -> left, 0, len + 1, ret) : helper(root -> right, 1, len + 1, ret);
        leftOrRight == 1 ? helper(root -> right, 1, 2, ret) : helper(root -> left, 0, 2, ret);
    }
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        helper(root -> left, 0, 2, ret);
        helper(root -> right, 1, 2, ret);
        return ret;
    }
};
// @lc code=end


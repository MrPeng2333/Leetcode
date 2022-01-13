/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int res;
    void helper(TreeNode* root, int val = 0) {
        if (!root) return;
        if (root -> left == root -> right) res += (val * 10 + root -> val);
        else {
            helper(root -> left, val * 10 + root -> val);
            helper(root -> right, val * 10 + root -> val);
        }
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};
// @lc code=end


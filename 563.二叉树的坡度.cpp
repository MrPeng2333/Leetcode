/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int res = 0;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int ls = helper(root -> left);
        int rs = helper(root -> right);
        res += abs(ls - rs);
        return ls + rs + root -> val;
    }
    int findTilt(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};
// @lc code=end


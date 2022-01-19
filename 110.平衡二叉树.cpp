/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int helper(TreeNode* root, bool &ret) {
        if (!root) return 0;
        if (!ret) return 0;
        int left = helper(root -> left, ret);
        int right = helper(root -> right, ret);
        if (abs(left - right) > 1) ret = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        helper(root, ret);
        return ret;
    }
};
// @lc code=end


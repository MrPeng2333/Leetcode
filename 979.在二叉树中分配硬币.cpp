/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int helper(TreeNode* root, int &ret) {
        if (!root) return 0;
        int left = helper(root -> left, ret);
        int right = helper(root -> right, ret);
        ret += abs(left) + abs(right);
        return root -> val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        helper(root, ret);
        return ret;
    }
};
// @lc code=end


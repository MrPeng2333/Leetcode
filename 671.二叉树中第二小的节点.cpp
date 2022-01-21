/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int helper(TreeNode* root, int minVal) {
        if (!root) return -1;
        if (root -> val != minVal) return root -> val;
        int left = helper(root -> left, minVal);
        int right = helper(root -> right, minVal);
        return left == -1 ? right : right == -1 ? left : min(left, right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root -> val);
    }
};
// @lc code=end


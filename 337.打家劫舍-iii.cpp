/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> helper(TreeNode* root) {
        if (!root) return vector<int>{0, 0};
        auto left = helper(root -> left);
        auto right = helper(root -> right);
        int leftMax = max(left[0], left[1]);
        int rightMax = max(right[0], right[1]);
        return vector<int>{leftMax + rightMax, left[0] + right[0] + root -> val};
    }
    int rob(TreeNode* root) {
        auto v = helper(root);
        return max(v[0], v[1]);
    }
};
// @lc code=end


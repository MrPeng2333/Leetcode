/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int ret;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left, right;
        left = helper(root -> left);
        right = helper(root -> right);
        int curRet = 0;
        int returnValue = 1;
        if (root -> left && root -> left -> val == root -> val) {
            curRet += left;
            returnValue = max(left + 1, returnValue);
        }
        if (root -> right && root -> right -> val == root -> val) { 
            curRet += right;
            returnValue = max(right + 1, returnValue);
        }
        ret = max(ret, curRet);
        return returnValue;
    }
    int longestUnivaluePath(TreeNode* root) {
        ret = 0;
        helper(root);
        return ret;
    }
};
// @lc code=end


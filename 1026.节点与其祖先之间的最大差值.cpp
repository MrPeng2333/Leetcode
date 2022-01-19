/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root, int maxVal = 0, int  minVal = INT_MAX) {
        if (!root) return -1;
        if (root -> left == root -> right) return max(maxVal, root -> val)- min(minVal, root -> val);
        int left = maxAncestorDiff(root -> left, max(maxVal, root -> val), min(minVal, root -> val));
        int right = maxAncestorDiff(root -> right, max(maxVal, root -> val), min(minVal, root -> val));
        return left == -1 ? right : right == -1 ? left : max(left, right);
    }
};
// @lc code=end


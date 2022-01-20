/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    void helper(TreeNode* root, int &ret, int maxVal) {
        if (!root) return;
        if (root -> val >= maxVal) ret++;
        helper(root -> left, ret, max(maxVal, root -> val));
        helper(root -> right, ret, max(maxVal, root -> val));
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        int maxVal = root -> val;
        helper(root, ret, maxVal);
        return ret;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!cloned) return cloned;
        if (cloned -> val == target -> val) return cloned;
        TreeNode* left = getTargetCopy(original, cloned -> left, target);
        return !left ? getTargetCopy(original, cloned -> right, target) : left;
    }
};
// @lc code=end


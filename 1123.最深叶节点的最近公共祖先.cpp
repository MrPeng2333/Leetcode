/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* ret;
    int helper(TreeNode* root, int level, int &maxLevel) {
        if (!root) return 0;
        if (root -> left == root -> right) {
            if (level < maxLevel) return 0;
            maxLevel = level;
            ret = root;
            return maxLevel;
        }
        int l = helper(root -> left, level + 1, maxLevel);
        int r = helper(root -> right, level + 1, maxLevel);
        if (l == r && l == maxLevel) {
            ret = root;
            return maxLevel;
        }
        return max(l, r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxLevel = 0;
        ret = nullptr;
        helper(root, 0, maxLevel);
        return ret;
    }
};
// @lc code=end


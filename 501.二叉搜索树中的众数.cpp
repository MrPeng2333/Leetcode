/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> ret;
    int cnt = 0;
    int maxFreq = 0;
    TreeNode* pre = nullptr;
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root -> left);
        if (pre && pre -> val == root -> val) {
            cnt++;
        } else {
            cnt = 1;
            pre = root;
        }
        
        if (cnt > maxFreq) {
            maxFreq = cnt;
            ret = {};
            ret.push_back(root -> val);
        } else if (cnt == maxFreq) ret.push_back(root -> val);
        helper(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        return ret;
    }
};
// @lc code=end


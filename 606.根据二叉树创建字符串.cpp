/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* root) {
        string ret = "";
        if (!root) return ret;
        ret += to_string(root -> val);
        if (root -> left == root -> right) return ret;
        ret += "(";
        if (!root -> left) {
            ret += ")(";
            ret += tree2str(root -> right);
        } else if (!root -> right) {
            ret += tree2str(root -> left);
        } else {
            ret += tree2str(root -> left);
            ret += ")(";
            ret += tree2str(root -> right);
        }
        ret += ")";
        return ret;
        
    }
};
// @lc code=end


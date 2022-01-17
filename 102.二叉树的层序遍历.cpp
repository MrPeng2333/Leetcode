/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node -> val);
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};
// @lc code=end


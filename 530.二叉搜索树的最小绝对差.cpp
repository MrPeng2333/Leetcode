/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        int ret = INT_MAX;
        int preN = -1;
        while (1) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            if (st.empty()) break;
            root = st.top();
            st.pop();
            if (preN != -1) ret = min(ret, root -> val - preN);
            preN = root -> val;
            root = root -> right;
        }
        return ret;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        stack<TreeNode*> st;
        st.push(root);
        root = root -> left;
        vector<int> ret;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            if (st.empty()) break;
            root = st.top();
            st.pop();
            ret.push_back(root -> val);
            root = root -> right;
        }
        return ret;
    }
};
// @lc code=end


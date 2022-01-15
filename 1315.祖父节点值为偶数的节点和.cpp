/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    void helper(TreeNode* root, int &ret) {
        if (!root) return;
        if (!(root -> val % 2)) {
            if (root -> left) {
                TreeNode* leftChild = root -> left;
                ret += leftChild-> left ? leftChild -> left -> val : 0;
                ret += leftChild-> right ? leftChild -> right -> val : 0;
            }
            if (root -> right) {
                TreeNode* rightChild = root -> right;
                ret += rightChild-> left ? rightChild -> left -> val : 0;
                ret += rightChild-> right ? rightChild -> right -> val : 0;
            }
        }
        helper(root -> left, ret);
        helper(root -> right, ret);


    }
    int sumEvenGrandparent(TreeNode* root) {
        int ret = 0;
        helper(root, ret);
        return ret;
    }
};
// @lc code=end


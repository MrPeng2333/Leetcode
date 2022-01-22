/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    
    TreeNode* helper(vector<int> &preArr, int s, int e) {
        if (s > e) return nullptr;
        TreeNode* node = new TreeNode(preArr[s]);
        int idx, i;
        for (i = s; i <= e; i++) {
            if (preArr[i] > preArr[s]) {
                idx = i;
                break;
            }
        }
        if (i > e) idx = e + 1;
        node -> left = helper(preArr, s + 1, idx - 1);
        node -> right = helper(preArr, idx, e);
        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end


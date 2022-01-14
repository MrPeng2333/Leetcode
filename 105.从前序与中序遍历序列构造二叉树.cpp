/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* helper(int &preIdx, int inStart, int inEnd, vector<int> &preArr, vector<int> &inArr) {
        if (inStart > inEnd) return nullptr;
        TreeNode* node = new TreeNode(preArr[preIdx++]);
        int index;
        for (int i = inStart; i <= inEnd; i++) {
            if (inArr[i] == node -> val) {
                index = i;
                break;
            }
        }
        node -> left = helper(preIdx, inStart, index - 1, preArr, inArr);
        node -> right = helper(preIdx, index + 1, inEnd, preArr, inArr);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preIdx, 0, inorder.size() - 1, preorder, inorder);
    }
};
// @lc code=end


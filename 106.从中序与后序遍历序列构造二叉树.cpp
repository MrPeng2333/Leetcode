/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* helper(int &postIdx, int inStart, int inEnd, vector<int> &inArr, vector<int> &postArr) {
        if (inStart > inEnd) return nullptr;
        TreeNode* node = new TreeNode(postArr[postIdx]);
        postIdx--;
        int rootIdx;
        for (int i = inStart; i <= inEnd; i++) {
            if (inArr[i] == node -> val) {
                rootIdx = i;
                break;
            }
        }
        node -> right = helper(postIdx, rootIdx + 1, inEnd, inArr, postArr);
        node -> left = helper(postIdx, inStart, rootIdx - 1, inArr, postArr);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        return helper(postIdx, 0, inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end


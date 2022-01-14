/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* helper(int &preIdx, int &postIdx, vector<int> &preArr, vector<int> &postArr) {
        if (preIdx >= preArr.size() || postIdx >= postArr.size()) return nullptr;
        TreeNode* node =  new TreeNode(preArr[preIdx]);
        preIdx++;
        if (node -> val != postArr[postIdx]) node -> left = helper(preIdx, postIdx, preArr, postArr);
        if (node -> val != postArr[postIdx]) node -> right = helper(preIdx, postIdx, preArr, postArr);
        postIdx++;
        return node;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0, postIdx = 0;
        return helper(preIdx, postIdx, preorder, postorder);
    }
};
// @lc code=end


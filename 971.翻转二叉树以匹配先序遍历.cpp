/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    bool helper(TreeNode* root, vector<int> &preArr, vector<int> &ret, int &idx) {
        if (!root) return true;
        if (root -> val != preArr[idx]) return false;
        int oriIdx = idx;
        idx++;
        bool left = helper(root -> left, preArr, ret, idx);
        if (left) return helper(root -> right, preArr, ret, idx);
        
            idx = oriIdx;
            idx++;
            left = helper(root -> right, preArr, ret, idx);
            bool right = helper(root -> left, preArr, ret, idx);
            if (left && right) {
               ret.push_back(root -> val);
                return true;
            }
            return false;
        
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ret;
        int idx = 0;
        if (!helper(root, voyage, ret, idx)) return vector<int>(1, -1);
        return ret;
    }
};
// @lc code=end


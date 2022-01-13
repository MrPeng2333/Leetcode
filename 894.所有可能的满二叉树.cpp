/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    TreeNode* clone(TreeNode* node) {
        TreeNode* newNode = new TreeNode(0);
        newNode -> left = node -> left ? clone(node -> left) : nullptr;
        newNode -> right = node -> right ? clone(node -> right) : nullptr;
        return newNode;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ret;
        if (n == 1) {
            return vector<TreeNode*>{1, new TreeNode(0)};
        } else if (n % 2) {
            for (int i = 2; i <= n; i += 2) {
                vector<TreeNode*> left = allPossibleFBT(i - 1);
                vector<TreeNode*> right = allPossibleFBT(n - i);
                for (int lIdx = 0; lIdx < left.size(); lIdx++) {
                    for (int rIdx = 0; rIdx < right.size(); rIdx++) {
                        ret.emplace_back(new TreeNode(0));
                        ret.back() -> left = (rIdx == right.size() - 1) ? left[lIdx] : clone(left[lIdx]);
                        ret.back() -> right = (lIdx == left.size() - 1) ? right[rIdx] : clone(right[rIdx]);
                    }
                }
            }
        }
        return ret;

    }
};
// @lc code=end

